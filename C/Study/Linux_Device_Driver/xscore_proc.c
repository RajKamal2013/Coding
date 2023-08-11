/*
 * Module to test the proc fs implementation
 * Author : Raj Kamal <rajkamal2013@gmail.com>
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <proc_fs.h>
#include <linux/init.h>
#include <linux/errno.h>

/* Global Variable */
struct proc_dir_entry *proc_root_xscore = NULL;
struct proc_dir_entry *proc_root_xcpm = NULL;
struct proc_dir_entry *proc_root_xcpm_ports = NULL;

/* Function Prototypes */
int xscore_create_procfs_entries(void);
static int xcpm_port_proc_read_device(struct file *, char __user *, size_t , loff_t *);
static int xcpm_port_proc_write_device(struct file *, const char *, unsigned long , loff_t *);
void xcpm_port_add_proc_entry(char *name);
void xcpm_port_remove_proc_entry(char *name);
static int xscore_proc_write_systemid(struct file *, const char *, unsigned long, loff_t *);
static int xscore_proc_read_systemid(struct file *, char __user *, size_t, loff_t *);
static int xscore_proc_write_info(struct file *, const char *, unsigned long, loff_t *);
static int xscore_proc_read_info(struct file *, char __user *, size_t, loff_t *);
static int xscore_proc_write_debug(struct file *, const char *, unsigned long, loff_t *);
static int xscore_proc_read_debug(struct file *, char __user *, size_t, loff_t *);


static int xcpm_port_read_systemid (struct file *file, const __user *buffer,
				unsigned long size, loff_t *) {
	

static int  xcpm_port_proc_show_device(struct seq_file *m, void *v) {
        struct xscore_port *ib_port = (struct xscore_port *)data;
        struct ib_port_attr port_attr;
        u64 fw_ver;
        unsigned long tsecs = 0, tmins = 0, thrs = 0;

        (void) ib_query_port(ib_port->xs_dev->device, ib_port->port_num, &port_attr);

        seq_printf(m, "Device name: \t\t%s\n", ib_port->xs_dev->device->name);
        fw_ver = ib_port->xs_dev->fw_ver;
        seq_printf(m, "Device FW Version: \t%d.%d.%d\n", (int)(fw_ver >> 32),
                        (int)((fw_ver >> 16) & 0xFFFF), (int)(fw_ver & 0xFFFF));
        seq_printf(m, "Port: \t\t\t%d\n", ib_port->port_num);
        seq_printf(m, "Port %s: \t\t0x%llx\n",
                ib_port->link_layer == IB_LINK_LAYER_ETHERNET?
                        "MAC" : "GUID", ib_port->guid);
        seq_printf(m, "Port PhysState: \t%s\n",
                        ib_port_phys_state_str[port_attr.phys_state]);
        page +=
            sprintf(page, "Port State: \t\t%s\n",
                    port_state2str[port_attr.state]);
        if (ib_port->link_layer == IB_LINK_LAYER_INFINIBAND) {
                seq_printf(m, "Port LID: \t\t%d\n", port_attr.lid);
                seq_printf(m, "Port SM LID: \t\t%d\n",
                                port_attr.sm_lid);
        } else {
                if (ib_port->xs_dev->is_shca == 0 && port_attr.active_mtu == 4)
                        port_attr.active_mtu = 5;
        }
        calc_time_fjiffies(ib_port->rec_poller_time, &tsecs, &tmins, &thrs);
        seq_printf(m, "Last XCM poll :\t\t%lu hrs %lu mins %lu seconds\n",
                        thrs, tmins, tsecs);

 	seq_printf(m, "Port XCM poll state: \t%d\n",
                        ib_port->rec_poller_state);

        //IB8KTBD this reports wrong mtu for 8k IB Mtu defined for softhca
        seq_printf(m, "Port MTU: \t\t%d (%d)\n", port_attr.active_mtu,
                        xg_ib_mtu_enum_to_int(port_attr.active_mtu));

        seq_printf(m, "Port Link Layer: \t%s\n",
                        port_linkLayer2str[ib_port->link_layer]);
        seq_printf(m, "\n");
        if (ib_port->link_layer == IB_LINK_LAYER_INFINIBAND) {
                seq_printf(m, "Port XDS LID: \t\t%d\n",
                                ib_port->xds_lid);
                seq_printf(m, "Port XDS GUID: \t\t0x%llx\n",
                                ib_port->xds_guid);
        }
        seq_printf(m, "\n");

        seq_printf(m, "Port Not Active Counter: \t%d\n",
                        ib_port->counters[PORT_XDS_PORT_NOT_ACTIVE_COUNTER]);
        seq_printf(m, "SA Query Error Counter: \t%d\n",
                        ib_port->counters[PORT_XDS_SA_QUERY_ERROR_COUNTER]);
        seq_printf(m, "SA Query Timeout Counter: \t%d\n",
                        ib_port->counters[PORT_XDS_SA_QUERY_TOUT_COUNTER]);
        seq_printf(m, "SA Query Counter: \t\t%d\n",
                        ib_port->counters[PORT_XDS_SA_QUERY_COUNTER]);
        seq_printf(m, "XDS Query Counter: \t\t%d\n",
                        ib_port->counters[PORT_XDS_XDS_QUERY_COUNTER]);
        seq_printf(m, "XDS Query Error Counter: \t%d\n",
                        ib_port->counters[PORT_XDS_XDS_QUERY_ERROR_COUNTER]);
        seq_printf(m, "XDS List Count Zero Counter: \t%d\n",
                        ib_port->counters[PORT_XDS_LIST_COUNT_ZERO_COUNTER]);
        seq_printf(m, "XDS Query Timeout Counter: \t%d\n",
                        ib_port->counters[PORT_XDS_XDS_QUERY_TOUT_COUNTER]);
        seq_printf(m, "XDS List Count Counter: \t%d\n",
                        ib_port->counters[PORT_XDS_LIST_COUNT_COUNTER]);

	return 0;
}

/* start of Module */
int init_module(void) {
        printk(KERN_INFO "Procfs creation for xscore testing. \n");

        return 0;
}

/* End of module */
void cleanup_module(void) {
        printk(KERN_INFO "Proc_fs deletion for xscore created for testing. \n");
        return 0;
}


/* Function creating proc fs entries for the module */
int xscore_create_procfs_entries(void) {
	int ret = 0;
	struct proc_dir_entry *file_d = NULL;

	proc_root_xscore = proc_mkdir("/driver/xscore", NULL);
	if (!proc_root_xscore) {
		printk (KERN_ERR "unable to create /proc/driver/xscore\n");
		return-ENOMEM;
	}

	struct const file_operations xscore_debug_fops = {
		.owner = THIS_MODULE,
		.read  = xscore_proc_read_debug,
		.write = xscore_proc_write_debug
	};
	file_d = proc_create ("debug", S_IFREG, proc_root_xscore,
		    &xscore_debug_fops);
	if (!file_d) {
		printk (KERN_ERR "unable to create /proc/driver/xscore/debug.\n");
		ret = -ENOMEM;
		goto no_debug;
	}
	

	struct const file_operations xscore_systemid_fops = {
		.owner = THIS_MODULE,
		.read = xscore_proc_read_systemid,
		.write = xscore_proc_write_systemid
	};
	file_d = proc_create ("systemid", S_IFREG, proc_root_xscore,
			&xscore_systemid_fops);
	if (!file_d) {
		printk (KERN_ERR "unable to create /proc/driver/xscore/systemid.\n");
		ret = -ENOMEM;
		goto no_systemid;
	}

	struct const file_operations xscore_info_fops = {
		.owner = THIS_MODULE,
		.read = xscore_proc_read_info,
		.write = xscore_proc_write_info
	};
	file_d = proc_create ("info", S_IFREG, proc_root_xscore,
			&xscore_proc_info_fops);
	if (!file_d) {
		printk (KERN_ERR "Unable to create /proc/driver/xscore/info. \n");
		ret = -ENOMEM;
		goto no_info;
	}	
	
	proc_root_xcpm = proc_mkdir("xcpm", proc_root_xscore);
	if (!proc_root_xcpm) {
		printk(KERN_ERR "Unable to create /proc/driver/xscore/xcpm.\n");
		ret = -ENOMEM;
		goto no_xcpm;
	}

	proc_root_xcpm_ports = proc_mkdir("ports", proc_root_xcpm);
	if (!proc_root_xcpm_ports) {
		printk(KERN_ERR "Unable to create /proc/driver/xscore/xcpm/ports.\n");
		ret = -ENOMEM;
		goto no_ports;
	}

	return 0;
	
no_ports:
	remove_proc_entry("xcpm", proc_root_xscore);
no_xcpm:
	remove_proc_entry("info", proc_root_xscore);
no_info:
	remove_proc_entry("systemid", proc_root_xscore);
no_systemid:
	remove_proc_entry("debug", proc_root_xscore);
no_debug:
	remove_proc_entry("/driver/xscore", PROC_ROOT);
	return ret;
}



	
