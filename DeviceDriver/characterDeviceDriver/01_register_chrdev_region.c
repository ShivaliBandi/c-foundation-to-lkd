#include <linux/module.h>   // Kernel module APIs: module_init(), module_exit(), MODULE_LICENSE()
#include <linux/kernel.h>   // Kernel logging functions such as pr_info()
#include <linux/fs.h>       // dev_t, register_chrdev_region(), unregister_chrdev_region()

static dev_t dev;           // Stores our device number (major + minor)

static int __init my_init(void)
{
    int ret;                // Stores return value from register_chrdev_region()

    // Create starting device number:
    // Major = 100
    // Minor = 5
    dev = MKDEV(100, 5);

    // Reserve 4 consecutive device numbers:
    // 100:5
    // 100:6
    // 100:7
    // 100:8
    ret = register_chrdev_region(dev, 4, "mydriver");

    // Check whether registration succeeded
    if (ret < 0)
    {
        pr_err("register_chrdev_region failed\n");
        return ret;
    }

    // Print the major and starting minor number
    pr_info("Major = %d, Minor = %d\n", MAJOR(dev), MINOR(dev));

    return 0;
}

static void __exit my_exit(void)
{
    // Release the same 4 device numbers
    unregister_chrdev_region(dev, 4);

    pr_info("Device numbers unregistered\n");
}

module_init(my_init);       // Tell kernel to call my_init() when module loads
module_exit(my_exit);       // Tell kernel to call my_exit() when module unloads

MODULE_LICENSE("GPL");     // Declare module license


/*
OUTPUT:
shivali-bandi@programmerInsane:~/Documents/c-foundation-to-lkd/DeviceDriver/characterDeviceDriver$ sudo dmesg | tail
[   65.185394] 01_register_chrdev_region: loading out-of-tree module taints kernel.
[   65.185408] 01_register_chrdev_region: module verification failed: signature and/or required key missing - tainting kernel
[   65.185706] Major = 100, Minor = 5
[  290.989730] workqueue: acpi_os_execute_deferred hogged CPU for >13333us 4 times, consider switching to WQ_UNBOUND
[  318.503615] workqueue: acpi_os_execute_deferred hogged CPU for >13333us 5 times, consider switching to WQ_UNBOUND
[ 3144.084810] workqueue: acpi_ec_event_processor hogged CPU for >13333us 4 times, consider switching to WQ_UNBOUND
[ 3395.250542] Device numbers unregistered



shivali-bandi@programmerInsane:~/Documents/c-foundation-to-lkd/DeviceDriver/characterDeviceDriver$ grep mydriver /proc/devices
100 mydriver
*/