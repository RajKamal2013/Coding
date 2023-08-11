/*
 * Module to create proc entry
 * Author : Raj Kamal <rajkamal2013@gmail.com>
 */

/* Files included */
#include <linux/module.h>	/* module programming */
#include <linux/kernel.h>	/* needed for printk */
#include <linux/init.h>		/* for macros */
#include <linux/proc_fs.h>	/* for proc_fs support */
#include <linux/seq_file.h>
#include <linux/fs.h>		/* for fops support */
#include <asm/uaccess.h>	/* for communication */
#include <linux/errno.h>	/* for error codes */

/* Module Information */
#define DRIVER_AUTHOR "RajKamal<rajkamal2013@gmail.com>"
#define DRIVER_DESC   "driver for sample proc file"

/* Global variables */
int len, temp;
char *msg;

static int proc_open(struct inode *inode, struct file *file);
static int proc_read(struct seq_file *m, void *data);

struct file_operations proc_fops = {
	.owner		= THIS_MODULE,
	.open		= proc_open,  
	.read  		= seq_read,
	.llseek		= seq_lseek,
	.release	= single_release,
	};

struct proc_dir_entry *proc_root_proc = NULL;
/* reading fucntions */
static int proc_read(struct seq_file *m, void *data) {
	printk (KERN_INFO "Inside proc_read().\n");
	seq_printf(m, "Message : %s.\n", msg);
	printk (KERN_INFO "Inside proc_read().\n");
	return 0;
}

static int proc_open(struct inode *inode, struct file *file) {
	printk(KERN_INFO "Inside proc_open().\n");
	return single_open(file, proc_read, NULL);
}

/* Function that creates new proc_entry */
void create_new_proc_entry(void ) {
	int ret = 0;

	printk(KERN_INFO "Inside create_new_proc_entry().\n");
	proc_root_proc = proc_create("helloproc", 777, NULL, &proc_fops);
	if (!proc_root_proc) {
		printk (KERN_ERR "unable to create /proc/hello. \n");
		ret = -ENOMEM;
	}
	
	msg = "Hello World! .\n";
	len = strlen(msg);
	temp = len;
	printk (KERN_INFO "1. len = %d msg = %s.\n", len, msg);

}

/* initializing fucntion for module */
int proc_init(void) {
	int ret = 0;
	printk(KERN_INFO "Inside proc_init().\n");
	create_new_proc_entry();
	return ret;
}		

/* clean up fucntion for module */
void proc_cleanup(void) {
	printk(KERN_INFO "Inside proc_cleanup().\n");
	remove_proc_entry("hello", NULL);
	printk (KERN_INFO "Removed the proc entry /proc/hello.\n");
}

/*Initialising module information */
MODULE_LICENSE ("GPL");         /* license for module */
MODULE_AUTHOR (DRIVER_AUTHOR);  /* who is author */
MODULE_DESCRIPTION (DRIVER_DESC); /*module description */
module_init(proc_init);
module_exit(proc_cleanup);
