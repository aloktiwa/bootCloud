#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/interrupt.h>
#include <linux/uaccess.h>
#include <linux/ioctl.h>

#define IRQ_BOOT 12
#define WR_BOOT _IOW('a',1,int32_t *)
#define RD_BOOT _IOR('a',2,int32_t *)

#define MODULE_NAME "aioctl_ztp"
MODULE_AUTHOR("local");

static char *name = "Bilbo";
module_param(name, charp, S_IRUGO);

int boot_open(struct inode *inode,struct file *fp)
{
	printk(KERN_INFO" open driver \n");
	return 0;
}
ssize_t boot_read(struct file *fp,char __user *outb,size_t nbytes,loff_t *offset)
{
	int ret =0;
	printk(KERN_INFO" read driver \n");

	return ret;
}
ssize_t boot_write(struct file *fp,const char __user *inpb,size_t nbytes, loff_t *offset)
{
	printk(KERN_INFO" write open driver \n");

	return 0;
}
//int boot_ioctl(struct file *fp,unsigned int cmd,unsigned long val){
int boot_ioctl(struct inode *in, struct file *fp,unsigned int cmd,unsigned long val){

	switch (cmd) {
		case WR_BOOT:
			printk(KERN_INFO" write boot ioctl command \n");
			break;
		case RD_BOOT:
			printk(KERN_INFO" read boot ioctl command \n");
			break;
		default:
			printk(KERN_INFO" invalid ioctl command \n");
			break;
	}

	printk(KERN_INFO" ioctl driver \n");
	return 0;
}
int boot_release(struct inode *inode , struct file *fp)
{

	printk(KERN_INFO" release driver \n");
	return 0;
}


static struct file_operations bootFops = {
	owner: THIS_MODULE,
	open: boot_open,
	release: boot_release,
	read: boot_read,
	unlocked_ioctl: boot_ioctl, // compat_ioctl here
	write: boot_write
};

static dev_t dev =0;
static struct cdev bootCdev;
static struct class *boot_class;
#define BOOT_DEV "boot_device"

static irqreturn_t boot_irq(int irqnu,void *irqdata)
{
	printk(KERN_INFO"IRQ Handler call %d \n",irqnu);

	// schedule_work(&workqueue
	return IRQ_HANDLED;
}
static int __init boot_start(void)
{
	if(alloc_chrdev_region(&dev,0,1,BOOT_DEV) < 0) {
		printk(KERN_ERR"canot alloc majot num\n");
		return -1;
	}

	// 
	printk(KERN_INFO"Major and min number %d %d \n",MAJOR(dev),MINOR(dev));
	cdev_init(&bootCdev,&bootFops);

	// adding chr dev in system
	if(cdev_add(&bootCdev,dev,1) < 0 ) {
		printk(KERN_ERR"cdev add issue \n");
		goto r_class;
	}

	if((boot_class = class_create(THIS_MODULE,BOOT_DEV))  == NULL ) {
		printk(KERN_ERR"class creation error \n");
		goto r_class;
	}

	if((device_create(boot_class,NULL,dev,NULL,BOOT_DEV)) == NULL) {
		printk(KERN_ERR"device create error \n");
		goto r_device;
	}
	if((request_irq(IRQ_BOOT,boot_irq,IRQF_SHARED,BOOT_DEV,(void *) (boot_irq)))) {
	
		printk(KERN_ERR"request irq failed \n");
		goto r_class;
	}
	return 0;

// return error case 
r_device:
	class_destroy(boot_class);
r_class:
	unregister_chrdev_region(dev,1);
	return -1;
}

static void __exit boot_exit(void)
{
	device_destroy(boot_class,dev);
	class_destroy(boot_class);
	cdev_del(&bootCdev);
	unregister_chrdev_region(dev,1);
    pr_info("%s: goodbye %s\n", MODULE_NAME, name);
    pr_info("%s: module unloaded from 0x%p\n", MODULE_NAME, boot_exit);
}

module_init(boot_start);
module_exit(boot_exit);




MODULE_DESCRIPTION("this is boot device for arm board \n");
