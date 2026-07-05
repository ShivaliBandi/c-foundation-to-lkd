#include<stdio.h>
#define VERSION 2


/*
#if evaluates a compile-time constant expression. If the expression is non-zero, 
the enclosed code is included; otherwise, it is excluded during preprocessing.

⭐ Difference Between #ifdef and #if
#ifdef

Question:

Does this feature exist?

Examples:

DEBUG
ENABLE_SSL
CONFIG_X86
#if

Question:

What is the value?

Examples:

Version numbers
Buffer sizes
Memory limits
Compiler versions
Product editions
⭐ Interview Answer

Interviewer: Where is #if used?

You can answer:

"#if is used when compile-time decisions depend on the value of a constant expression rather than just the existence of a macro. Common use cases include API version checks, Linux kernel version compatibility, compiler version checks, product editions, hardware configuration, and buffer or memory size selection."

⭐⭐⭐⭐⭐

📝 Add this to your notes
Directive	Primary Use Case
#ifdef	Check if a feature/macro exists (DEBUG, CONFIG_SMP)
#ifndef	Include guards, default values
#if	Compare numeric values (versions, sizes, compiler versions, product editions)
#elif	Multiple compile-time choices
#else	Default compile-time branch
💡 Easy way to remember
#ifdef → "Does it exist?"
#ifndef → "Does it not exist?"
#if → "What is its value?"

This one-line distinction is what interviewers are usually looking for.
*/
int main()
{

    #if VERSION == 1

    printf("V1");

    #elif VERSION == 2

    printf("V2");

    #else

    printf("Unknown");

    #endif
    return 0;
}