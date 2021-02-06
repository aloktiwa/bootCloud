// module related 
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>
// kthread 
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/interrupt.h>


static struct task_struct * chr_thread;

void tasklet_fun(unsigned long data);

static struct tasklet_struct * tasklet_example;
//DECLARE_TASKLET(tasklet_example,tasklet_fun,100);

// define tasklet func
void tasklet_fun(unsigned long data)
{
	printk(KERN_INFO"tasklet func start data =%ld \n",data);

}



//  Define the module metadata.
#define MODULE_NAME "athread"
MODULE_AUTHOR("Alok Tiwari");
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("A simple kernel module to greet a user");
MODULE_VERSION("0.1");

//  Define the name parameter.
static char *name = "Bilbo";
module_param(name, charp, S_IRUGO);
MODULE_PARM_DESC(name, "The name to display in /var/log/kern.log");
static int athread_fun(void *p) {
	int i=0;
	printk("athread func \n");
	while(!kthread_should_stop()) {
		printk("athread func while running %d \n",i++);
		msleep(1000);
	}

	return 0;
}
static int __init athread_init(void)
{

	// this should be interrupt handler 
	tasklet_example = (struct tasklet_struct *)kmalloc(sizeof(struct tasklet_struct),GFP_KERNEL);

	tasklet_init(tasklet_example,tasklet_fun,100);
	tasklet_schedule(tasklet_example);
#if 0
	chr_thread = kthread_create(athread_fun,NULL,"chr athread");
	if(chr_thread != NULL) {
		wake_up_process(athread_fun);
	} else {
		printk("unable to create thread \n");
	}
#else 
	chr_thread = kthread_run(athread_fun,NULL,"chr athread");
	if(chr_thread) {
		printk("create thread and run \n");
	}

#endif
    pr_info("%s: module loaded at 0x%p\n", MODULE_NAME, athread_init);
    pr_info("%s: greetings %s\n", MODULE_NAME, name);
    return 0;
}

static void __exit athread_exit(void)
{
	tasklet_kill(tasklet_example);
	if(chr_thread != NULL) {
		kthread_stop(chr_thread);
	}
    pr_info("%s: goodbye %s\n", MODULE_NAME, name);
    pr_info("%s: module unloaded from 0x%p\n", MODULE_NAME, athread_exit);
}

module_init(athread_init);
module_exit(athread_exit);
