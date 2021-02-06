#!/bin/sh
#
if [ -f /etc/debug ]; then set -x; fi
EXEC=$(cd -P -- "$(dirname -- "$0")" && printf '%s\n' "$(pwd -P)/$(basename -- "$0")")
EXEC_PATH=`dirname ${EXEC}`
cd $EXEC_PATH

#CONSOLE_SPEED=%%CONSOLE_SPEED%%
#CONSOLE_DEV=%%CONSOLE_DEV%%
#CONSOLE_FLAG=%%CONSOLE_FLAG%%
#CONSOLE_PORT=%%CONSOLE_PORT%%

setup_onie_para()
{
  CONSOLE_SPEED=9600
  CONSOLE_DEV=0
  ONSOLE_PORT=0x2f8
  CONSOLE_FLAG=1
  EXTRA_CMDLINE_LINUX=%%EXTRA_CMDLINE_LINUX%%
  if `cat /proc/cmdline | grep -q 115200`; then
     CONSOLE_SPEED=115200
  fi
  if `cat /proc/cmdline | grep -q ttyS1`; then
     CONSOLE_DEV=1
  fi
  if `setserial -g /dev/ttyS${CONSOLE_DEV} | grep -q 3f8`; then
     CONSOLE_PORT=0x3f8
  fi
  export CONSOLE_SPEED
  export CONSOLE_DEV
  export CONSOLE_FLAG
  export CONSOLE_PORT
  export EXTRA_CMDLINE_LINUX
}

# use /tmp for self-extracting only under ONIE
if [ -x /fabos/libexec/hasmd ]; then
   tmp_folder=/support/extr/dist
else
   tmp_folder=/tmp/extr/dist
fi
diag_folder=${tmp_folder}/diag
packages=${tmp_folder}/packages
onie_recovery=${tmp_folder}/onie-recovery
onie_target=${tmp_folder}/onie-target

mkdir -p ${tmp_folder}
if [ -f "packages.tgz" ]; then
   tar zxf packages.tgz -C ${tmp_folder}
fi
if [ -f "chroot_fs.tgz" ]; then
   tar zxf chroot_fs.tgz -C ${tmp_folder}
fi
if [ -f "onie-recovery.tgz" ]; then
   tar zxf onie-recovery.tgz -C ${tmp_folder}
fi
if [ -f "onie-target.tgz" ]; then
   tar zxf onie-target.tgz -C ${tmp_folder}
   cp ${tmp_folder}/onie-target/hostos_install.sh .
   cp ${tmp_folder}/onie-target/nos_install.sh .
   cp ${tmp_folder}/onie-target/nos_upgrade.sh .
   cp ${tmp_folder}/onie-target/os_install_common .
   mkdir -p ${packages}/onie-target
   cp ${tmp_folder}/onie-target/os_install_common ${packages}/onie-target
fi

export packages
export tmp_folder
export onie_target

if [ ! -x /bin/onie-sysinfo ]; then
   echo "SLX OS firmware upgrade"
   TARGET_INSTALLER=nos_upgrade.sh
else
   setup_onie_para
   hostname onie
   cp ${tmp_folder}/onie-target/sin /sbin
   if [ -f ${tmp_folder}/onie-target/baremetal ]; then
      touch /etc/baremetal
   fi
   export HOSTBD=`/sbin/sin 2>/dev/null | grep "HOST" | cut -d ':' -f 2`
   export TARGBD=`/sbin/sin 2>/dev/null | grep "SWBD" | cut -d ':' -f 2`
   export TYPEID=`/sbin/sin 2>/dev/null | grep "TYPE" | cut -d ':' -f 2`

   if [ -n "$HOSTBD" ] && [ ! -f /etc/baremetal ]; then
      echo "Host OS and SLX VM install ..."
      TARGET_INSTALLER=hostos_install.sh
   else
      echo "Bare Metal SLX OS install ..."
      TARGET_INSTALLER=nos_install.sh
   fi
fi
${EXEC_PATH}/${TARGET_INSTALLER}
exit 0
