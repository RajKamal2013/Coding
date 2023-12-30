/*
 * Module to create proc entry
 * Author : Raj Kamal <rajkamal2013@gmail.com>
 */

/* Files included */
#include <linux/errno.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/utsname.h>

/* Module Information */
#define DRIVER_AUTHOR "RajKamal<rajkamal2013@gmail.com>"
#define DRIVER_DESC   "driver for sample proc file"


struct proc_dir_entry *proc_root_xscore = NULL;
struct proc_dir_entry *proc_root_xscore_info = NULL;
struct proc_dir_entry *proc_root_xscore_ports = NULL;
struct xscore_port_data {
	int count;
	char name[100];
};
struct xscore_info {
	char name[100];
	char msg[100];
};

static ssize_t xscore_port_proc_write_device(struct file *file, const char __user *buffer,
                                 size_t count, loff_t *offp);
static int xscore_port_proc_read_device(struct seq_file *m, void *data);
static int xscore_port_open_proc_device(struct inode *inode, struct file *file);
static int xscore_port_add_proc_entry(struct xscore_port_data *port);
static int xscore_proc_open_info(struct inode *inode, struct file *file);
static int xscore_proc_read_info(struct seq_file *m, void *data);
static ssize_t xscore_proc_write_info(struct file *file, const char __user *buffer, size_t count,
				loff_t *offp);
static int xscore_port_remove_proc_entry(struct xscore_port_data *port_data);
static int xscore_info_remove_proc_entry(void);

static const struct file_operations xscore_ports_fops = {
                .owner		= THIS_MODULE,
                .open		= xscore_port_open_proc_device,
                .read		= seq_read,
               // .write		= xscore_port_proc_write_device,
		.llseek		= seq_lseek,
		.release	= single_release, 
};

static const struct file_operations xscore_info_fops = {
                .owner		= THIS_MODULE,
		.open		= xscore_proc_open_info,
                .read		= seq_read,
              //  .write		= xscore_proc_write_info,
		.llseek		= seq_lseek,
		.release	= single_release,
};

static ssize_t xscore_port_proc_write_device(struct file *file, const char __user *buffer,
                                 size_t count, loff_t *offp)
{
        struct xscore_port_data *port_data = NULL;

	printk(KERN_INFO "Inside xscore_port_proc_write.\n");

        file->private_data = PDE_DATA(file_inode(file));
        port_data= (struct xscore_port_data *)file->private_data;

        memset(port_data->name, 0, sizeof (port_data->name));
        return count;
}

static int xscore_port_proc_read_device(struct seq_file *m, void *data)
{
	struct xscore_port_data *port_data = (struct xscore_port_data *)m->private;

	printk(KERN_INFO "Inside xscore_port_proc_read_device. %p\n", data);
	if (data == NULL) {
		printk(KERN_ERR "Data is NULL for xscore_port_proc_read_device.\n");
		return -ENOMEM;
	}

	seq_printf(m, "GUID 0x50800200008e4d38.\n");
	seq_printf(m, "Device name:\t\t%s.\n", port_data->name);
	seq_printf(m, "Device Count:\t\t%d.\n", port_data->count);
	return 0;
}

static int xscore_port_open_proc_device(struct inode *inodep, struct file *file) {
	printk(KERN_INFO "Inside xscore_port_open_proc_device().\n");

        return single_open(file, xscore_port_proc_read_device, PDE_DATA(inodep));
}

static int xscore_port_add_proc_entry(struct xscore_port_data *port)
{
        struct proc_dir_entry *file;
	int ret = 0;
	//char *name = "XscoreGuid";
	struct xscore_port_data *port_data = port;

	printk(KERN_INFO "Inside xscore_port_add_proc_entry().\n");
	printk(KERN_INFO "port->data : %s, port->count= %d.\n", port->name, port->count);

        file= proc_create_data(port_data->name, S_IFREG, proc_root_xscore_ports,
                    &xscore_ports_fops, port);
        if (!file) {
                printk (KERN_ERR "unable to create /proc/driver/Xscore/Ports/%s.\n", port_data->name);
		ret = -ENOMEM;
        }
	return ret;

}

static int xscore_port_remove_proc_entry(struct xscore_port_data *port)
{
	printk(KERN_INFO "Inside xscore_port_remove_proc_entry().\n");
	printk(KERN_INFO "removing %s .\n", port->name);

        remove_proc_entry(port->name, proc_root_xscore_ports);
	return 0;
}

static int xscore_info_remove_proc_entry(void)
{
	printk(KERN_INFO "Inside xscore_info_remove_proc_entry().\n");

        remove_proc_entry("Info", proc_root_xscore);
	return 0;
}
static ssize_t xscore_proc_write_info(struct file *file, const char __user *buffer,
                                 size_t count, loff_t *offp)
{
	printk (KERN_INFO "Inside xscore_proc_write_info().\n");

        file->private_data = PDE_DATA(file_inode(file));
        return count;
}

static int xscore_proc_read_info(struct seq_file *m, void *data)
{
	printk(KERN_INFO "Inside xscore_proc_read_info().\n");

	seq_printf(m, "Xscore Read Info: Yes This is Dummy proc_read.\n");
	seq_printf(m, "Xscore Read Info Message: Successfully Tested.\n");
	return 0;
}	

static int xscore_proc_open_info(struct inode *inodep, struct file *file) {
	printk(KERN_INFO "Inside xscore_proc_open_info().\n");

        return single_open(file, xscore_proc_read_info, PDE_DATA(inodep));
}

int xscore_create_procfs_entries(void)
{
        int ret = 0;
        struct proc_dir_entry *file_d = NULL;
	struct xscore_port_data port;
	
	printk(KERN_INFO "Inside the xscore_create_procfs_entries().\n");

	sprintf(port.name, "0x50800200008e4d3b");
	port.count = 2;
	
	proc_root_xscore = proc_mkdir("driver/Xscore", NULL);
	if (!proc_root_xscore) {
                printk(KERN_ERR "Unable to create /proc/driver/Xscore\n");
                return -ENOMEM;
        }

	file_d = proc_create_data("Info", S_IFREG, proc_root_xscore,
                                &xscore_info_fops, NULL);
	if (!file_d) {
                printk(KERN_ERR 
                        "Unable to create /proc/driver/Xscore/Info\n");
                ret = -ENOMEM;
	}
	proc_root_xscore_ports = proc_mkdir("Ports", proc_root_xscore);
	if (!proc_root_xscore_ports) {
                printk(KERN_ERR
                       "Unable to create /proc/driver/xscore/ports.\n");
                ret = -ENOMEM;
        }
	xscore_port_add_proc_entry(&port);
	return ret;
}



/* initializing fucntion for module */
int proc_init(void) {
        int ret = 0;

	printk(KERN_INFO "Inside init().\n");

	ret = xscore_create_procfs_entries();
        return ret;
}

/* clean up fucntion for module */
void proc_cleanup(void) {
	int ret = 0;
	struct xscore_port_data port_data;
	sprintf(port_data.name, "0x50800200008e4d3b");
        port_data.count = 2;
        printk (KERN_INFO "Removed the proc entry /proc/hello.\n");
	
	ret = xscore_port_remove_proc_entry(&port_data);
	ret = xscore_info_remove_proc_entry();
}

/*Initialising module information */
MODULE_LICENSE ("GPL");         /* license for module */
MODULE_AUTHOR (DRIVER_AUTHOR);  /* who is author */
MODULE_DESCRIPTION (DRIVER_DESC); /*module description */
module_init(proc_init);
module_exit(proc_cleanup);

