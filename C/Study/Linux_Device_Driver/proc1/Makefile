KDIR := /lib/modules/`uname -r`/build
MAKE = make
PWD := $(shell pwd)
EXTRA_CFLAGS += -g
obj-m += proc_entry1.o
obj-m += proc_entry2.o
obj-m += proc_entry3.o
obj-m += proc_entry4.o

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
clean :
	$(MAKE) -C $(KDIR) M=$(PWD) clean

