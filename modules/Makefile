obj-m:=hello.o
obj-modules:=hello.o
CURRENT_PATH:=$(shell pwd)
KERNEL_SRC:=/home/hon/f2fs

all:
	$(MAKE) -C $(KERNEL_SRC) M=$(CURRENT_PATH) modules
clean:
	rm *.ko
	rm *.o
