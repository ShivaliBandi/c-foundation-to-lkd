#include<stdio.h>
int main()
{
    int inum=0,bitSet=0;
    printf("Enter number and which bit needs to set 1 \n");
    scanf("%d %d",&inum,&bitSet);
    inum=inum | (1<<bitSet);
    printf("%d\n",inum);
    return 0;
}

/*

OR (|)

Rule: Result is 1 if at least one bit is 1.

A	B	A | B
0	0	0
0	1	1
1	0	1
1	1	1


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