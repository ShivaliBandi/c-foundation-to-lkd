savedcmd_01_register_chrdev_region.mod := printf '%s\n'   01_register_chrdev_region.o | awk '!x[$$0]++ { print("./"$$0) }' > 01_register_chrdev_region.mod
