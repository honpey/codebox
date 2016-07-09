#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("HONPEY");

static int __init hello_init(void) {
	printk(KERN_ALERT "HELLO WORLD enter");
	return 0;
}
static void __exit hello_exit(void) {
	printk(KERN_ALERT "Hello workd exit");
}

module_init(hello_init);
module_exit(hello_exit);

