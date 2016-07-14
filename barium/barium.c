#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kprobes.h>

static struct kprobe barium_kprobe ={
	.symbol_name = "f2fs_write_data_pages",
};
static int handler_pre(struct kprobe *p, struct pt_regs *regs)
{
	printk("hello pre handler\n");
	return 0;

}
static void handler_pos(struct kprobe *p, struct pt_regs *regs,
			unsigned long flags)
{
	printk("hello post handler\n");
}
static void __exit barium_cleanup_module(void)
{
	unregister_kprobe(&barium_kprobe);
	printk("clean..\n");
}
static int __init barium_init(void)
{
	int ret;
	printk("hello world\n");
	barium_kprobe.pre_handler = handler_pre;
	barium_kprobe.post_handler = handler_pos;
	ret = register_kprobe(&barium_kprobe);
	if (ret < 0) {
		printk("register_kprobe failed, return %d\n", ret);
		return ret;
	}
	printk("Planted kprobe at %p\n", barium_kprobe.addr);
	return 0;

}

module_init(barium_init);
module_exit(barium_cleanup_module);
MODULE_LICENSE("GPL");
