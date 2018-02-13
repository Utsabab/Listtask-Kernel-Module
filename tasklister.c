#include <linux/sched.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>


static int task_lister_init(void) {
	printk(KERN_INFO "lOADING MODULE...\n");

	struct task_struct *task;

	for_each_process(task) {
		printk (KERN_INFO "pid: %d | pname: %s | state: %ld\n", task->pid, task->comm, task->state);
		
	
		struct task_struct* current_state;
		current_state = task->real_parent;

		while (current_state->pid != 0) {
			printk (KERN_INFO "pancestorid: %d | pancestorname %s | pancestorstate: %ld\n", current_state->pid, current_state->comm, current_state->state);
			current_state = current_state->real_parent;
		}
		printk (KERN_INFO "ID, Name and state printed for this process & their ancestors\n\n");
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
