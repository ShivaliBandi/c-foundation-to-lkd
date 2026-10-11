#include<iostream>
#include<thread> //this headerfile is for threads
#include<atomic> // this headerfile is for atomic variable
using namespace std;
/*
Common Atomic Operations
The <atomic> header provides several operations for reading, modifying, and synchronizing atomic variables.

Function	Description
load()	Reads the current value of the atomic variable.
store()	Stores a new value into the atomic variable.
exchange()	Replaces the current value and returns the previous value.
fetch_add()	Atomically adds a value and returns the old value.


What does the second parameter actually do?

In multi-threaded programming, CPUs and compilers often reorder instructions to optimize performance. The memory_order parameter acts as a safety barrier. It tells the compiler and the CPU exactly how instructions around this atomic operation can or cannot be reordered across different threads.

The Most Common Options

You can pass one of several constants defined in the <atomic> header:
• std::memory_order_seq_cst (Default)
	• What it means: Sequential Consistency.
	• How it behaves: This is the safest and strictest option. It guarantees that all threads see all operations in the exact same, absolute order. If you are unsure what to use, stick with this default.
• std::memory_order_relaxed
	• What it means: No synchronization.
	• How it behaves: It only guarantees that the addition itself is atomic (no data races on that specific variable). However, it allows the compiler and CPU to aggressively reorder any surrounding reads or writes. This is ideal for simple counters (like a hit counter) where the exact order of surrounding operations doesn't matter.
• std::memory_order_acq_rel
	• What it means: Acquire-Release.
	• How it behaves: It ensures that changes made by one thread before releasing a lock/atomic variable become visible to another thread acquiring it. It prevents instructions from floating past this boundary.


fetch_sub()	Atomically subtracts a value and returns the old value.
fetch_and()	Performs an atomic bitwise AND operation.
fetch_or()	Performs an atomic bitwise OR operation.
fetch_xor()	Performs an atomic bitwise XOR operation.
wait()	Blocks until the atomic value changes. (C++20)
notify_one()	Wakes one waiting thread. (C++20)
notify_all()	Wakes all waiting threads. (C++20)
Note: wait(), notify_one(), and notify_all() were introduced in C++20, not C++11.


*/
atomic<int> counter={0};

void increment()
{
    for(int i=0;i<100000;i++)
    {
        counter.fetch_add(1,memory_order_relaxed);
    }
}
int main()
{
    thread t1(increment);
    thread t2(increment);

    t1.join(); //Waits for Thread 1 to finish.
    t2.join();


    cout<<"Count is "<<counter.load()<<endl;//Reads the current value of the atomic variable.

    
    return 0;
}
/*
output
 Count is 200000
*/