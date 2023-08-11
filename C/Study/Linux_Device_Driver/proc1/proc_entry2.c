/*
 * Module to create proc entry
 * Author : Raj Kamal <rajkamal2013@gmail.com>
 */

/* Files included */
#include <linux/module.h>	/* module programming */
#include <linux/kernel.h>	/* needed for printk */
#include <linux/init.h>		/* for macros */
#include <linux/proc_fs.h>	/* for proc_fs support */
#include <linux/fs.h>		/* for fops support */
#include <asm/uaccess.h>	/* for communication */
#include <linux/errno.h>	/* for error codes */
#include <linux/sched.h>	/* for slab */
#include <linux/slab.h>		/* for kmalloc */

/* Module Information */
#define DRIVER_AUTHOR "RajKamal<rajkamal2013@gmail.com>"
#define DRIVER_DESC   "driver for sample proc file"

/* Global variables */
int len, temp;
char *msg;


/* Functions prototypes */
void create_new_proc_entry(void);
int proc_read(struct file *filp, char *buf, size_t count, loff_t *offp);
int proc_write(struct file *filp, const char *buf, size_t count, loff_t *offp);


/* reading fucntions */
int proc_read(struct file *filp, char *buf, size_t count, loff_t *offp) {
	if (count > temp) {
		count = temp;
	}
	temp = temp - count;
	copy_to_user(buf, msg, count);
	if (count == 0) {
		temp = len;
	}
	return count;
}

/* writing function */
int proc_write(struct file *filp, const char *buf, size_t count, loff_t *offp) {
	copy_from_user (msg, buf, count);	
	len = count;
	temp = len;
	return count;
}

/* function that creates proc entry */
void create_new_proc_entry(void ) {
	int ret = 0;
	struct proc_dir_entry *proc_root_proc = NULL;
	struct file_operations proc_fops = {
		.owner = THIS_MODULE,
		.read  = proc_read,
		.write = proc_write
	};

	proc_root_proc = proc_create("hello2", 0, NULL, &proc_fops);
	if (!proc_root_proc) {
		printk (KERN_ERR "unable to create /proc/hello. \n");
		ret = -ENOMEM;
	}

	msg=kmalloc(GFP_KERNEL,10*sizeof(char));
	msg = "Hello World. \n";	
	
	//return ret;
}

/* initializing fucntion for module */
int proc_init(void) {
	int ret = 0;
	create_new_proc_entry();
	return ret;
}		

/* clean up fucntion for module */
void proc_cleanup(void) {
	remove_proc_entry("hello", NULL);
	printk (KERN_INFO "Removed the proc entry /proc/hello.\n");
}

/*Initialising module information */
MODULE_LICENSE ("GPL");         /* license for module */
MODULE_AUTHOR (DRIVER_AUTHOR);  /* who is author */
MODULE_DESCRIPTION (DRIVER_DESC); /*module description */
module_init(proc_init);
module_exit(proc_cleanup);
