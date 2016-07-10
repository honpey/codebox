scull-objs := main.o pipe.o access.o
obj-m	:= scull.o
KERNELDIR = /home/hon/f2fs
PWD       := $(shell pwd)

SCULL_DEBUG=1
modules:
	$(MAKE) ARCH=arm64 CROSS_COMPILE=aarch64-buildroot-linux-gnu- -C $(KERNELDIR) M=$(PWD) modules
clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions
