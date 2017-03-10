#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/sched.h>
#include<linux/cdev.h>
#include<asm/uaccess.h>
#include<linux/device.h>
#include<linux/slab.h>

MODULE_LICENSE("Dual BSD/GPL");

/**Constants**/
#define FIRST_MINOR 10
#define NR_DEVS 1 // Number of device numbers


// Function Declarations for syscall definitions
int myOpen (struct inode *inode, struct file *filep);
int myRelease (struct inode *in, struct file *fp);
long myIoctl (struct file * fp, unsigned int pro_id, unsigned long addr);
// Intialization routines
static int myInit (void);
static void myExit (void);
 

struct file_operations fops ={
		.owner = THIS_MODULE,
		.open = myOpen,
		.release = myRelease,
		.unlocked_ioctl = myIoctl 
};

/* Global variables */
char *devname; // constant device name 
int majNo;
static dev_t mydev; // encodes majopr number and minor number
struct cdev *my_cdev; // holds character device driver descriptor

/* To accept input from the command line */	
module_param(devname, charp, 0000);

// class and device structres
static struct class *mychar_class;
static struct device *mychar_device;	

/*
 * myOpen: open function of the sudo driver
 *
 */

int myOpen (struct inode *inode,struct file *filep)
{
	printk(KERN_INFO "Open sucessful\n");
	return 0;
}

/*
 * myRelease: close function of pseudo driver
 *
 */

int myRelease (struct inode *in, struct file *fp)
{
	printk(KERN_INFO "File released\n");
	return 0;
}

/*
 * myIoctl: Ioctl function of pseudo driver
 *
 */

long myIoctl (struct file * fp, unsigned int pro_id, unsigned long addr)
{	
	struct task_struct *task_ptr = NULL;
	struct vm_area_struct *t_vm = NULL;
	struct file * file_name = NULL;
	struct path file_path;
	struct dentry *direntry = NULL;
	
	task_ptr = find_task_by_vpid(pro_id);
	t_vm = (task_ptr->mm)->mmap;
	file_name = ((task_ptr->mm) -> mmap)->vm_file;
	file_path = (file_name->f_path);
	direntry = (file_path.dentry);

		printk( "address\t\t  perm  offset\t  Path\n");
	do{
		printk(KERN_INFO "%p-%p  ",t_vm->vm_start,t_vm->vm_end);
		((t_vm->vm_flags)&(1)) ? printk(KERN_CONT "r"):printk(KERN_CONT "-");
		((t_vm->vm_flags)&(2)) ? printk(KERN_CONT "w"):printk(KERN_CONT "-");
		((t_vm->vm_flags)&(4)) ? printk(KERN_CONT "x"):printk(KERN_CONT "-");
		((t_vm->vm_flags)&(8)) ? printk(KERN_CONT "S"):printk(KERN_CONT "P");
		printk(KERN_CONT "\t  %.08x\t",t_vm->vm_pgoff);
		printk(KERN_CONT "%s ", file_path->direntry->d_iname);
		printk(KERN_CONT "");
    	t_vm = t_vm->vm_next;
	}while(t_vm->vm_next != NULL );

	
	
	printk(KERN_INFO "process id in struct_task := %u\n",task_ptr->pid);
	printk(KERN_INFO "Ictl device of process %d\n",pro_id);
		
	return 0;
}
/*
 * myInit : init function of the kernel module
 *
 */

static int __init myInit (void)
{
	int ret = -ENODEV;
	int status;

	printk(KERN_INFO "Initializing Character Device\n");
	
	// Allocating Device Numbers
	status = alloc_chrdev_region (&mydev, FIRST_MINOR, NR_DEVS, devname);
	if(status < 0)
	{
		printk (KERN_NOTICE "Device number allocation failed: %d\n",status);
		goto err;
	}
	
	printk(KERN_INFO "Major number allocated=%d \n",MAJOR(mydev));
	my_cdev =cdev_alloc(); // Allocate memorey for my_cdev
	if (my_cdev == NULL) {
		printk (KERN_ERR "cdev_alloc failed\n");
		goto err_cdev_alloc;
	}
	
	cdev_init(my_cdev,&fops); // Initialize my_cdev with fops
	my_cdev->owner = THIS_MODULE;
	
	status = cdev_add (my_cdev, mydev, NR_DEVS); //Addmy_dev to the list
	if (status) {
		printk (KERN_ERR "cdev_add failed \n");
		goto err_cdev_add;
	}

	//	Create a class and an entry in sysfs
	mychar_class = class_create(THIS_MODULE, devname);
	if (IS_ERR(mychar_class)) {
		printk (KERN_ERR "class_create() failed\n");
		goto err_class_create;
	}

	// Create my_char device in sysfs and an
	// device entry will be made in /dev directory 
	mychar_device = device_create(mychar_class, NULL, mydev, NULL, devname);
	if (IS_ERR(mychar_device)) {
		printk (KERN_ERR "device_create() failed\n");
		goto err_device_create;
	}
	
	return 0;
	
	err_device_create:
		class_destroy (mychar_class);

	err_class_create:
		cdev_del (my_cdev);

	err_cdev_add:
		kfree (my_cdev);
	
	err_cdev_alloc:
		unregister_chrdev_region (mydev, NR_DEVS);
	
	err:
		return ret;
	}

/*
 *  myExit : cleanup function of th e kernel module
 *
 */
	
	static void myExit (void)
	{
		printk (KERN_INFO "Exiting the Charcater Driver\n");

		device_destroy (mychar_class, mydev);
		class_destroy (mychar_class);
		cdev_del(my_cdev);
		unregister_chrdev_region(mydev, NR_DEVS);

		return;
	}

module_init(myInit);
module_exit(myExit);
