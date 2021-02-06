#include <linux/module.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/kobject.h>
#include <linux/sysfs.h>
#include <linux/string.h>



unsigned int sysfs_val =0;
static struct kobject *kobj_val;

/* sysfs function */
static ssize_t sysfs_show(struct kobject *kobj,struct kobj_attribute *kattr,char *buff);
static ssize_t sysfs_store(struct kobject *kobj,struct kobj_attribute *kattr,const char *buff,size_t count);

static ssize_t sysfs_show(struct kobject *kobj,struct kobj_attribute *kattr,char *buff) 
{
	return 0;
}
static ssize_t sysfs_store(struct kobject *kobj,struct kobj_attribute *kattr,const char *buff,size_t count)
{
	return 0;
}
struct kobj_attribute sysfs_attr = __ATTR(sysfs_val,0660,sysfs_show,sysfs_store);


static int open_bootproc(struct inode *in,struct file *fp)
{
	return 0;
}
static int release_bootproc(struct inode *in,struct file *fp)
{
	return 0;
}
static ssize_t read_bootproc(struct file *fp,char __user *buf, size_t len , loff_t *offset)
{
	int ret =0;

	return ret;
}
static ssize_t write_bootproc(struct file *fp,const char *buf,size_t len, loff_t *offset)
{
	int ret =0;

	return ret;
}

static struct file_operations bootproc_fops = {
	.owner = THIS_MODULE,
	.open = open_bootproc,
	.read = read_bootproc,
	.write = write_bootproc,
	.release = release_bootproc
};
static int  __init mybootproc_init(void)
{

	// create a bootproc entry
	proc_create("boot_proc",0666,NULL,&bootproc_fops);
	printk(KERN_INFO" mybootproc_init call \n");

/* creating dir in /sys/kernel */
	kobj_val = kobject_create_and_add("my_sysfs",kernel_kobj);
	
	if(sysfs_create_file(kobj_val,&sysfs_attr.attr)) {
		printk(KERN_ERR"unabel to create sysfs file \n");
		kobject_put(kobj_val);
		sysfs_remove_file(kobj_val,&sysfs_attr.attr);
		return -1;
	}

	return 0;
}
static void __exit mybootproc_exit(void)
{
	printk(KERN_INFO" mybootproc exit module \n");
}


module_init(mybootproc_init);
module_exit(mybootproc_exit);
