#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x95393fd, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xf8a84a04, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0xafd7f39c, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xe6b76fe1, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0x95b315ca, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0x2a086732, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0x960853fd, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0xc406b214, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0x4697193, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0xb71b3a6d, __VMLINUX_SYMBOL_STR(cdev_alloc) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0xeb3a9e66, __VMLINUX_SYMBOL_STR(find_task_by_vpid) },
	{ 0x50eedeb8, __VMLINUX_SYMBOL_STR(printk) },
	{        0, __VMLINUX_SYMBOL_STR(mcount) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "2C4BB09A2B06E6A551D1B36");
