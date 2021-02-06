#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>

int boot_open(struct inode *inode,struct file *fp)
{

	return 0;
}
ssize_t boot_read(struct file *fp,char __user *outb,size_t nbytes,loff_t *offset)
{
}
ssize_t boot_write(struct file *fp,const __user *inpb,size_t nbytes, loff_t *offset)
{

	return 0;
}
int boot_ioctl(struct inode *in, struct file *fp,unsigned int cmd,unsigned long val){

	return 0;
}
int boot_release(struct inode *inode , struct file *fp)
{

	return 0;
}
struct file_operations fops = {
	open: boot_open,
	release: boot_release,
	read: boot_read,
	unlocked_ioctl: boot_ioctl, // compat_ioctl here
	write: boot_write
};

static int __init boot_start()
{
	return 0;

}

