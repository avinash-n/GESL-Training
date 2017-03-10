// System header files
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/mm.h>//
#include <linux/sched.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/highmem.h>
#include <asm/page.h>//
//#include <asm/pgtable-2level_types.h>//

MODULE_LICENSE("Dual BSD/GPL");

// Constants
#define FIRST_MINOR 10
#define NR_DEVS 1	// Number of device numbers

// Function declarations for syscall definitions
int myOpen (struct inode *inode, struct file *filep);
int myRelease (struct inode *in, struct file *fp);
long myIoctl (struct file *, unsigned int, unsigned long);


// Initialization routines
static int myInit (void);
static void myExit (void);

struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = myOpen,
	.release = myRelease,
	.unlocked_ioctl = myIoctl
};

// Global variables
char *devname;						// Contains device name
int majNo;								// Major number for the driver
static dev_t mydev;				// Encodes major number and minor number
struct cdev *my_cdev;			// Holds character device driver descriptor
struct task_struct *ptr;	// Pointer to task_struct to read pid
unsigned int i;						// Loop variable(pgd)
unsigned int j;						// Loop variable(pt)
unsigned long pgd_entry;	// Physical address entry in PGD
pte_t *pte_va_addr;				// Virtual address pointing at PT
unsigned long pte_entry;	// Physical address entry in PT
unsigned int *page_frame_va_addr;// Virtual address of Page frame

// To accept input from the command line
module_param (devname, charp, 0000);

// Class and device structures
static struct class *mychar_class;
static struct device *mychar_device;

// myOpen : Open function for the pseudo driver
int myOpen (struct inode *inode, struct file *filep) {
	printk (KERN_INFO "Open successful\n");
	return 0;
}

// myIoctl : Function to control characteristics of character special files
long myIoctl (struct file *fd, unsigned int pid, unsigned long addr) {
	printk (KERN_INFO "ioctl() function invoked\n");
	ptr = find_task_by_vpid(pid);
	printk (KERN_INFO "sys/PID of the current process --> %d\n", ptr->pid);
	printk (KERN_INFO "--------------------------PAGE TABLE"
										"------------------------------\n");
	printk (KERN_INFO "-------------PGD------------- "
										": ----------------PT----------------\n");

	for (i = 0; i < 1024; i++) {
		if (i == 0) printk (KERN_INFO "****Application space addresses in PGD****\n");
		else if (i == 768) printk (KERN_INFO "****Kernel space addresses in PGD****\n");

		if ((((ptr->mm->pgd) + i)->pgd)) {

			if (i < 768) {

				pgd_entry = (unsigned long) ((((ptr->mm->pgd) + i)->pgd) >> 12);
				printk (KERN_INFO "%3x --> %8lx --> %8p :: ",
						i, (((ptr->mm->pgd) + i)->pgd),	(kmap (&mem_map[pgd_entry])));

				pte_va_addr = (pte_t *) (kmap (&mem_map[pgd_entry]));

				for (j = 0; j < 1024; j++) {

					if ((pte_va_addr + j)->pte) {

		//				pte_entry = (unsigned long) (((pte_va_addr + j)->pte) >> 12);

						printk (KERN_INFO "\t\t\t\t\t%3x --> %8lx\n", 
						j, ((pte_va_addr + j)->pte)/*, (kmap (&mem_map[pte_entry]))*/);
					}
				}
			} else if (i > 767 && i < 770) {
				pgd_entry = (unsigned long) ((((ptr->mm->pgd) + i)->pgd) >> 12);
				printk (KERN_INFO "%3x --> %8lx --> %8lx --> %8p :: ",
						i, (((ptr->mm->pgd) + i)->pgd),	((((ptr->mm->pgd) + i)->pgd) | 0xc0000000), (kmap (&mem_map[pgd_entry])));

				pte_va_addr = (pte_t *) (kmap (&mem_map[pgd_entry]));

				for (j = 0; j < 1024; j++) {

					if ((pte_va_addr + j)->pte) {

						pte_entry = (unsigned long) (((pte_va_addr + j)->pte) >> 12);

						printk (KERN_INFO "\t\t\t\t\t%3x --> %8lx\n", 
						j, ((pte_va_addr + j)->pte)/*, ((((ptr->mm->pgd) + i)->pgd) | 0xc0000000)*/);
					}
				}
			}
		}
	}

	return 0;
}

// myRelease : Close function of pseudo driver
int myRelease (struct inode *in, struct file *fp) {
	printk(KERN_INFO "File released\n");
	return 0;
}

//myInit : Init function of the kernel module
static int __init myInit (void) {
	int ret = -ENODEV;
	int status;

	printk(KERN_INFO "Initializing character device\n");

	// Allocating device numbers
	status = alloc_chrdev_region (&mydev, FIRST_MINOR, NR_DEVS, devname);
	if (status < 0) {
		printk(KERN_NOTICE "Device numbers allocation failed: %d\n",
					status);
		goto err;
	}

	printk(KERN_INFO "Major number allocated = %d\n", MAJOR(mydev));
	my_cdev = cdev_alloc();	// Allocate memory for my_cdev
	if (my_cdev == NULL) {
		printk(KERN_ERR "cdev_alloc() failde\n");
		goto err_cdev_alloc;
	}

	cdev_init(my_cdev, &fops);	// Initialize my_cdev with fops
	my_cdev->owner = THIS_MODULE;

	status = cdev_add(my_cdev, mydev, NR_DEVS);	// Add my_cdev to list
	if (status) {
		printk(KERN_ERR "cdev_add() failed\n");
		goto err_cdev_add;
	}

	// Create a class and an entry in sysfs
	mychar_class = class_create(THIS_MODULE, devname);
	if (IS_ERR(mychar_class)) {
		printk(KERN_ERR "class_create() failed\n");
		goto err_class_create;
	}

	// Create mychar_device in sysfs and
	// Make a device entry in /dev directory
	mychar_device = device_create(mychar_class, NULL, mydev, NULL, devname);
	if (IS_ERR(mychar_device)) {
		printk(KERN_ERR "device_create() failed\n");
		goto err_device_create;
	}

	return 0;

err_device_create:
	class_destroy(mychar_class);

err_class_create:
	cdev_del(my_cdev);

err_cdev_add:
	kfree(my_cdev);

err_cdev_alloc:
	unregister_chrdev_region(mydev, NR_DEVS);

err:
	return ret;
}

// myExit : CLean up function of the kernel module
static void myExit (void) {
	printk(KERN_INFO "Exiting the character driver\n");

	device_destroy(mychar_class, mydev);
	class_destroy(mychar_class);
	cdev_del(my_cdev);
	unregister_chrdev_region(mydev, NR_DEVS);

	return;
}

module_init(myInit);
module_exit(myExit);
