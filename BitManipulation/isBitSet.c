#include<stdio.h>
int main()
{
    int inum=0,bitSet=0;
    printf("Enter number and which bit to check is set or not\n");
    scanf("%d %d",&inum,&bitSet);
    if((inum&(1<<bitSet))!=0)
        printf("%d -> %d bit is set\n",inum,bitSet);
    else
        printf("bit is not set\n");

    return 0;
}
/*
AND (&)

Rule: Result is 1 only if both bits are 1.

A	B	A & B
0	0	0
0	1	0
1	0	0
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