#include <linux/sched.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>


static int task_lister_init(void) {
	printk(KERN_INFO "lOADING MODULE...\n");

	struct task_struct *task;

	for_each_process(task) {
		printk (KERN_INFO "pid: %d | pname: %s | state: %ld\n", task->pid, task->comm, task->state);
	}

	printk(KERN_INFO "MODULE LOADED\n");
	return 0;
}

static void task_lister_exit(void) {
	printk (KERN_INFO "REMOVING MODULE\n");
}

module_init(task_lister_init);
module_exit(task_lister_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Task lister");
MODULE_AUTHOR("UK");