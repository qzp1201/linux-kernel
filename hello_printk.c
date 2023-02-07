/*
 * "Hello, world!" minimal kernel module
 *
 * Valerie Henson <val@nmt.edu>
 *
 */

/*
 * The below are header files provided by the kernel which are
 * required for all modules.  They include things like the definition
 * of the module_init() macro.
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/fdtable.h>
#include <linux/fs.h>
#include <linux/binfmts.h>

/*
 * This is the init function, which is run when the module is first
 * loaded.  The __init keyword tells the kernel that this code will
 * only be run once, when the module is loaded.
 */

static int __init
hello_init(void)
{
	printk("VAS Info Extractor!\n");
	printk("state offset in task struct: %lu\n",offsetof(struct task_struct,state));
	printk("pid offset in task struct: %lu\n",offsetof(struct task_struct,pid));
	printk("tgid offset in task struct: %lu\n",offsetof(struct task_struct,tgid));
	printk("comm offset in task struct: %lu\n",offsetof(struct task_struct,comm));
	printk("struct mm_struct mm offset in task struct: %lu\n",offsetof(struct task_struct,mm));
	printk("struct files_struct files offset in task struct: %lu\n",offsetof(struct task_struct,files));
	printk("struct task_struct real_parent offset in task struct: %lu\n",offsetof(struct task_struct,real_parent));        
	printk("task struct: %p\n", struct task_struct);

	printk("pgd offset in struct mm_struct: %lu\n",offsetof(struct mm_struct,pgd));
	printk("struct vm_area_strut *mmap offset in struct mm_struct: %lu\n",offsetof(struct mm_struct,mmap));
	printk("vm_start offset in struct vm_area_struct: %lu\n",offsetof(struct vm_area_struct,vm_start));
	printk("vm_end offset in struct vm_area_struct: %lu\n",offsetof(struct vm_area_struct,vm_end));
	printk("struct file *vm_file offset in struct vm_area_struct: %lu\n",offsetof(struct vm_area_struct,vm_file));
	printk("struct vm_area_struct *vm_next offset in struct vm_area_struct: %lu\n",offsetof(struct vm_area_struct,vm_next));

	printk("struct fdtable fdt offset in struct files_struct: %lu\n",offsetof(struct files_struct,fdt));
	printk("struct file fd offset in struct fdtable: %lu\n",offsetof(struct fdtable,fd));
	printk("struct path f_path offset in struct file: %lu\n",offsetof(struct file,f_path));
	printk("struct dentry *dentry offset in struct path: %lu\n",offsetof(struct path,dentry));
	printk("char* d_iname offset in struct dentry: %lu\n",offsetof(struct dentry,d_iname));

	printk("filename offset in struct linux_binprm: %lu\n",offsetof(struct linux_binprm,filename));

	return 0;
}

/*
 * The below macro informs the kernel as to which function to use as
 * the init function.
 */

module_init(hello_init);

/*
 * Similary, the exit function is run once, upon module unloading, and
 * the module_exit() macro identifies which function is the exit
 * function.
 */

static void __exit
hello_exit(void)
{
	printk("Goodbye, world!\n");
}

module_exit(hello_exit);

/*
 * MODULE_LICENSE() informs the kernel what license the module source
 * code is under, which affects which symbols it may access in the
 * main kernel.  Certain module licenses will "taint" the kernel,
 * indicating that non-open or untrusted code has been loaded.
 * Modules licensed under GPLv2 do not taint the kernel and can access
 * all symbols, but declaring it so is a legal statement that the
 * source code to this module is licensed under GPLv2, and so you must
 * provide the source code if you ship a binary version of the module.
 */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Valerie Henson <val@nmt.edu>");
MODULE_DESCRIPTION("\"Hello, world!\" minimal module");
MODULE_VERSION("printk");
