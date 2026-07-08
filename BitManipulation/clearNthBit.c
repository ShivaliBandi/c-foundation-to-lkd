#include<stdio.h>
int main()
{
    int inum=0,bitSet=0;
    printf("Enter number and which bit needs to clear \n");
    scanf("%d %d",&inum,&bitSet);
    inum=inum & ~(1<<bitSet);
    printf("%d\n",inum);
    return 0;
}
/*
NOT (~)

This is a unary operator, so it has only one operand.

A	~A
0	1
1	0


Left Shift (<<)

Moves all bits to the left.

Example:

00000001 << 1

↓

00000010
00000001 << 2

↓

00000100
00000001 << 3

↓

00001000
Think
1 << n = 2ⁿ

Used for:

✅ Create bit masks
Right Shift (>>)

Moves all bits to the right.

Example:

00001000 >> 1

↓

00000100
00001000 >> 2

↓

00000010
*/