# Makefile + Kbuild — My Notes

## Why am I learning this?

For LDD hands-on, I have to write `.c` kernel module files and actually compile/load them.

A normal C program can be compiled like:

```bash
gcc main.c -o main
```

But a kernel module is different. I cannot just treat it like a normal userspace C program.

For kernel modules I use:

```text
.c file
   ↓
Makefile
   ↓
make
   ↓
Kbuild
   ↓
.ko file
   ↓
insmod
   ↓
kernel
```

---

# 1. What is `make`?

`make` is a build tool.

Instead of manually writing all compilation commands, I put the build instructions in a **Makefile**.

Example:

```makefile
hello:
	echo Hello
```

Then:

```bash
make hello
```

Make reads the Makefile and executes the command.

So:

```text
Makefile = instructions
make     = executes those instructions
```

For kernel modules, `make` is used to start the kernel build process.

---

# 2. What is a Makefile?

A Makefile is just a file containing rules/instructions for building something.

It can contain:

- targets
- commands
- dependencies
- variables

Example:

```makefile
all:
	echo Building
```

Here:

```text
all:
```

is a target.

The command below it tells Make what to do.

Important: the command under a target normally starts with a **TAB**.

---

# 3. What is Kbuild?

Kbuild = **Linux kernel build system**.

Linux kernel is huge:

```text
kernel/
drivers/
fs/
mm/
net/
block/
arch/
...
```

So building kernel code needs many kernel-specific rules.

Kbuild handles things related to:

- kernel configuration
- kernel headers
- architecture
- compiler options
- dependencies
- module building
- module metadata
- symbol/version information
- generated files

Kbuild is built on top of Make.

So I can think:

```text
Make
 ↓
general build system

Kbuild
 ↓
Linux-kernel-specific build system
```

Kbuild uses Make, but Kbuild provides the special rules needed for kernel code.

---

# 4. Why can't I just use GCC?

For a normal C program:

```bash
gcc main.c -o main
```

is fine.

But my driver contains kernel headers:

```c
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
```

and it has to be built for a particular kernel.

My running kernel:

```bash
uname -r
```

gave:

```text
7.0.0-29-generic
```

I also checked:

```bash
ls /lib/modules/$(uname -r)/build
```

and the kernel build directory exists.

The kernel build system knows the required environment and rules.

Therefore for external kernel modules I use **Kbuild**, not just:

```bash
gcc driver.c
```

---

# 5. What is an external module?

My driver source is outside the Linux kernel source tree.

My directory is:

```text
~/Documents/c-foundation-to-lkd/DeviceDriver/characterDeviceDriver
```

So this is an **external kernel module**.

Kbuild provides a standard way to build external modules.

---

# 6. My directory structure

I am keeping one Makefile for all the character-device-driver exercises.

Currently:

```text
characterDeviceDriver/
│
├── 01_register_chrdev_region.c
└── Makefile
```

Later it can become:

```text
characterDeviceDriver/
│
├── 01_register_chrdev_region.c
├── 02_cdev.c
├── 03_file_operations.c
├── 04_open.c
├── ...
└── Makefile
```

I will use the same Makefile for this directory.

---

# 7. My Makefile

My current Makefile is:

```makefile
obj-m += 01_register_chrdev_region.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
```

There are three important pieces:

```text
obj-m
all:
clean:
```

The first tells Kbuild what to build.

The second defines the normal build operation.

The third defines the cleanup operation.

---

# 8. `obj-m`

This line:

```makefile
obj-m += 01_register_chrdev_region.o
```

tells Kbuild:

> Build `01_register_chrdev_region.o` as a loadable kernel module.

The important part is:

```text
obj-m
```

`obj` → object

`m` → module

So I remember:

```text
obj-m = build this object as a module
```

---

# 9. Why `.o` when my file is `.c`?

My source is:

```text
01_register_chrdev_region.c
```

but in the Makefile I write:

```text
01_register_chrdev_region.o
```

because the build process first produces an object file.

Basic flow:

```text
01_register_chrdev_region.c
             ↓
            .o
             ↓
            .ko
```

So:

```text
.c = source code

.o = object file

.ko = kernel object / loadable kernel module
```

The important file I eventually load is:

```text
01_register_chrdev_region.ko
```

---

# 10. What does `+=` mean?

In:

```makefile
obj-m += 01_register_chrdev_region.o
```

`+=` means:

> Add this to the variable.

I can have multiple modules:

```makefile
obj-m += driver1.o
obj-m += driver2.o
```

So one Makefile can manage multiple module files.

For my current learning directory, I can add new exercises later.

---

# 11. What is `all:`?

I have:

```makefile
all:
```

This is a Make target.

When I run:

```bash
make
```

Make normally starts with the first/default target, which here is `all`.

The command below `all:` is:

```makefile
make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
```

So:

```text
make
 ↓
all target
 ↓
run Kbuild command
```

---

# 12. Understanding `-C`

This part:

```bash
-C /lib/modules/$(shell uname -r)/build
```

`-C` means:

> Change to this directory before doing the Make operation.

So I am telling Make to use the kernel build directory.

For my current kernel:

```text
7.0.0-29-generic
```

the path becomes:

```text
/lib/modules/7.0.0-29-generic/build
```

---

# 13. Understanding `$(shell uname -r)`

This:

```makefile
$(shell uname -r)
```

means:

> Run the shell command `uname -r` and put its output here.

I ran:

```bash
uname -r
```

and got:

```text
7.0.0-29-generic
```

Therefore:

```makefile
/lib/modules/$(shell uname -r)/build
```

becomes:

```text
/lib/modules/7.0.0-29-generic/build
```

This is better than hardcoding the kernel version because if my running kernel changes, the Makefile automatically gets the new version.

---

# 14. What is `/lib/modules/<kernel>/build`?

This directory points to the kernel build environment for the kernel.

For me:

```text
/lib/modules/7.0.0-29-generic/build
```

I checked it with:

```bash
ls /lib/modules/$(uname -r)/build
```

and saw things like:

```text
arch
drivers
fs
include
kernel
mm
net
scripts
Makefile
Kbuild
Module.symvers
...
```

So this is where the kernel's build infrastructure is available.

---

# 15. Understanding `M=$(PWD)`

This is another important part:

```makefile
M=$(PWD)
```

`PWD` = current working directory.

I am currently inside:

```text
characterDeviceDriver/
```

So `$(PWD)` represents that directory.

`M=$(PWD)` tells Kbuild:

> My external module source is in this directory.

So I remember:

```text
-C
 ↓
where is the kernel build system?

M=
 ↓
where is my external module?
```

---

# 16. Understanding `modules`

At the end:

```bash
modules
```

is a Kbuild target.

It tells the kernel build system to build the external modules specified by the Makefile.

So this whole command:

```bash
make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
```

means:

> Use the current kernel's build system, use my current directory as the external module directory, and build the module(s) defined there.

---

# 17. Full meaning of the command

The complete command:

```bash
make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
```

I can break it like this:

```text
make
 ↓
start Make

-C /lib/modules/$(shell uname -r)/build
 ↓
use the kernel build directory

M=$(PWD)
 ↓
my external module is here

modules
 ↓
build the external module
```

Plain English:

> Go to the build system of my running kernel, tell Kbuild that my external module is in my current directory, and build the module.

---

# 18. What does `clean:` do?

My Makefile also has:

```makefile
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
```

Now I can run:

```bash
make clean
```

This asks Kbuild to clean generated build files.

After building I may have:

```text
.c
.o
.ko
other generated files
```

After:

```bash
make clean
```

the generated build artifacts are cleaned.

I don't need to manually delete all those files.

---

# 19. What files did Kbuild create?

After I ran:

```bash
make
```

extra files appeared.

Examples:

```text
01_register_chrdev_region.o
01_register_chrdev_region.ko
Module.symvers
modules.order
.tmp_versions/
.01_register_chrdev_region.o.cmd
```

This is normal.

Kbuild needs these files during the build process.

The file I care about most for loading the module is:

```text
01_register_chrdev_region.ko
```

---

# 20. `.o` vs `.ko`

Important distinction:

```text
01_register_chrdev_region.o
```

→ object file

```text
01_register_chrdev_region.ko
```

→ kernel module

So I remember:

```text
.c
 ↓
source

.o
 ↓
object

.ko
 ↓
loadable kernel module
```

---

# 21. Building the module

I go to:

```text
characterDeviceDriver/
```

and run:

```bash
make
```

The flow is:

```text
Makefile
   ↓
make
   ↓
Kbuild
   ↓
compile/build
   ↓
01_register_chrdev_region.ko
```

If I get a compiler/Kbuild error, the module build failed.

If I get a `.ko`, the build stage succeeded.

---

# 22. Loading the `.ko`

After building:

```bash
sudo insmod 01_register_chrdev_region.ko
```

`insmod` asks the kernel to load the `.ko` file.

If loading succeeds:

```text
.ko
 ↓
kernel module loader
 ↓
module initialization
 ↓
my_init()
```

Because my source contains:

```c
module_init(my_init);
```

the kernel knows that `my_init()` is the module initialization function.

---

# 23. What happens in my current exercise?

When the module loads:

```c
my_init()
```

runs.

First:

```c
dev = MKDEV(100, 5);
```

This creates:

```text
major = 100
minor = 5

device = 100:5
```

Then:

```c
register_chrdev_region(dev, 4, "mydriver");
```

requests four consecutive device numbers:

```text
100:5
100:6
100:7
100:8
```

Then:

```c
pr_info("Major = %d, Minor = %d
",
        MAJOR(dev), MINOR(dev));
```

prints:

```text
Major = 100, Minor = 5
```

---

# 24. How do I see kernel output?

For kernel messages I use:

```bash
sudo dmesg | tail -20
```

My module used:

```c
pr_info()
```

so I can see the message in the kernel log.

For example:

```text
Major = 100, Minor = 5
```

This tells me that `my_init()` actually ran.

---

# 25. Removing the module

I remove it using:

```bash
sudo rmmod 01_register_chrdev_region
```

This causes:

```c
my_exit()
```

to run because I have:

```c
module_exit(my_exit);
```

Inside `my_exit()`:

```c
unregister_chrdev_region(dev, 4);
```

releases:

```text
100:5
100:6
100:7
100:8
```

So:

```text
insmod
 ↓
my_init()
 ↓
register

rmmod
 ↓
my_exit()
 ↓
unregister
```

---

# 26. Very important: build and load are different

I should not confuse:

```bash
make
```

with:

```bash
sudo insmod driver.ko
```

They do different things.

### `make`

Builds the module.

```text
.c
 ↓
.o
 ↓
.ko
```

### `insmod`

Loads the already-built `.ko` into the kernel.

```text
.ko
 ↓
kernel
```

So:

```text
make = build

insmod = load
```

---

# 27. A module can build but fail to load

This happened to me.

The module compiled successfully:

```text
make
 ↓
.ko created
```

But:

```bash
sudo insmod 01_register_chrdev_region.ko
```

initially failed with:

```text
Key was rejected by service
```

I checked:

```bash
mokutil --sb-state
```

and got:

```text
SecureBoot enabled
```

The kernel log showed:

```text
Loading of unsigned module is rejected
```

So the problem was not my C code.

It happened during module loading.

The flow was:

```text
.c
 ↓
make
 ↓
.ko
 ↓
insmod
 ↓
signature verification
 ↓
rejected
```

This taught me:

> Build success does not always mean load success.

---

# 28. Secure Boot lesson

Secure Boot can cause the kernel to reject an unsigned external module.

Useful commands:

```bash
mokutil --sb-state
```

and:

```bash
sudo dmesg | tail -30
```

If I see:

```text
Key was rejected by service
```

I should investigate module signature/Secure Boot instead of immediately changing my driver code.

For our development machine, after changing the Secure Boot configuration, the module was allowed to load.

---

# 29. "Tainted kernel" message

When my module loaded, I also saw:

```text
loading out-of-tree module taints kernel
```

and:

```text
module verification failed: signature and/or required key missing - tainting kernel
```

This is related to loading an external/untrusted unsigned module.

For my current learning exercise, the important point is:

```text
Major = 100, Minor = 5
```

was printed, so initialization succeeded.

I should understand the message, but I don't need to turn kernel taint into a huge topic right now.

---

# 30. Common mistakes I should avoid

### 1. Using GCC directly

Don't do:

```bash
gcc 01_register_chrdev_region.c
```

for this kernel-module build.

Use:

```bash
make
```

which invokes Kbuild.

### 2. Confusing `.o` and `.ko`

```text
.o = object file

.ko = loadable kernel module
```

### 3. Thinking `make` loads the module

It doesn't.

```text
make
 ↓
build

insmod
 ↓
load
```

### 4. Forgetting cleanup

If I reserve device numbers:

```c
register_chrdev_region(dev, 4, ...);
```

I need to release them:

```c
unregister_chrdev_region(dev, 4);
```

when the module is removed.

### 5. Changing driver code when the problem is module loading

If:

```text
make succeeds
```

but:

```text
insmod fails
```

I need to diagnose the loading problem separately.

---

# 31. My complete mental picture

I should think of it as three stages.

## Stage 1 — I write the source

```text
01_register_chrdev_region.c
```

## Stage 2 — I build it

```text
Makefile
   ↓
make
   ↓
Kbuild
   ↓
01_register_chrdev_region.ko
```

## Stage 3 — I load it

```text
.ko
 ↓
insmod
 ↓
kernel module loader
 ↓
my_init()
 ↓
driver code executes
```

Then removal:

```text
rmmod
 ↓
my_exit()
 ↓
cleanup
```

---

# 32. Interview questions

## What is Kbuild?

> Kbuild is the Linux kernel's build system built on top of Make. It provides kernel-specific build rules and handles things such as kernel configuration, compiler options, dependencies and building kernel modules.

## Why not compile a kernel module directly with GCC?

> A kernel module needs to be built against the target kernel's headers, configuration, architecture, compiler options and module infrastructure. Kbuild provides the required kernel-specific build environment and rules.

## What does `obj-m` mean?

> It tells Kbuild that the specified object should be built as a loadable kernel module.

Example:

```makefile
obj-m += mydriver.o
```

## What is `.ko`?

> `.ko` is the kernel object file used as a loadable kernel module.

## What does `-C` mean?

> It tells Make to change to the specified directory before performing the Make operation.

## What does `M=$(PWD)` mean?

> It tells Kbuild where my external module source/build directory is.

## What does `$(shell uname -r)` do?

> It runs `uname -r` and substitutes the running kernel version into the path.

## Can a module compile successfully but fail to load?

Yes.

For example:

```text
make
 ↓
successful
 ↓
.ko created
 ↓
insmod
 ↓
load failure
```

Possible reasons include:

- Secure Boot/module signature rejection
- missing symbols
- incompatible module/kernel
- invalid module metadata
- initialization failure
- resource conflicts

---

# 33. Commands I should know

Check kernel:

```bash
uname -r
```

Check compiler:

```bash
gcc --version
```

Check kernel build environment:

```bash
ls /lib/modules/$(uname -r)/build
```

Build:

```bash
make
```

Clean:

```bash
make clean
```

Load:

```bash
sudo insmod 01_register_chrdev_region.ko
```

Check module:

```bash
lsmod | grep 01_register_chrdev_region
```

Kernel logs:

```bash
sudo dmesg | tail -20
```

Remove:

```bash
sudo rmmod 01_register_chrdev_region
```

Secure Boot:

```bash
mokutil --sb-state
```

---

# 34. What I actually need to remember

I don't need to memorize every Kbuild internal detail.

The important things are:

```text
Make
 ↓
general build tool

Makefile
 ↓
build instructions

Kbuild
 ↓
Linux kernel build system

obj-m
 ↓
build object as module

.c → .o → .ko
 ↓

insmod
 ↓
load .ko into kernel

rmmod
 ↓
remove module
```

And this command:

```bash
make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
```

means:

```text
-C
→ use kernel build directory

M=$(PWD)
→ my external module is here

modules
→ build my external module
```

---

# 35. My current hands-on workflow

For every LDD module I should practice this cycle:

```text
Write code
   ↓
Understand code
   ↓
make
   ↓
check build result
   ↓
get .ko
   ↓
insmod
   ↓
check dmesg
   ↓
test
   ↓
rmmod
   ↓
check cleanup
   ↓
debug if anything fails
```

The goal is not just:

```text
"run make and insmod"
```

I should understand what happens at every step.

---

# 36. One-line summary

> Make reads the Makefile, the Makefile tells Kbuild what to build, Kbuild builds the external kernel module, the `.ko` is loaded using `insmod`, and the module's init/exit functions handle setup and cleanup inside the kernel.
