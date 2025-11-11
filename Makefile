# LKAI Kernel Module Makefile
# If you don't understand Makefiles, go learn.

obj-m += lkai.o
lkai-objs := src/lkai_main.o src/tensor_ops.o src/solana_verify.o

KDIR ?= /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

# Compiler flags that actually matter
ccflags-y := -DLKAI_VERSION="0.1.0" -Werror -Wall

.PHONY: all clean install load unload

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	rm -f Module.symvers modules.order

install: all
	sudo cp lkai.ko /lib/modules/$(shell uname -r)/extra/
	sudo depmod -a

load:
	sudo insmod lkai.ko

unload:
	sudo rmmod lkai

# For the lazy
reload: unload load

# Debug build - more printk noise
debug:
	$(MAKE) -C $(KDIR) M=$(PWD) modules ccflags-y="-DDEBUG -DLKAI_VERSION="0.1.0-debug" -g"
