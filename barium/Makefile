obj-m := barium.o

KERNELDIR = /home/hon/f2fs
PWD := $(shell pwd)

module:
	$(MAKE) ARCH=arm64 CROSS_COMPILE=aarch64-buildroot-linux-gnu- -C $(KERNELDIR) M=$(PWD) modules
clean:
	rm -rf *.o *.ko *.order *.symvers *.mod.c
install:
	mv *.ko /home/hon/f2fs/share_aarch64/
