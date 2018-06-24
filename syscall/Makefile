obj-m = hack_syscall.o

#transport_ring_buffer.o
KVER:=$(shell uname -r)
KVER=4.4.0-21-generic
CURRENT_PATH:=$(shell pwd)
all:
	make -C /lib/modules/$(KVER)/build M=$(CURRENT_PATH) modules
clean:
	rm -f *.ko *.o *.mod.c *.order Module.symvers
load:
	insmod fslook.ko
unload:
	rmmod fslook.ko
ls:
	lsmod | grep fslook 2>/dev/null
