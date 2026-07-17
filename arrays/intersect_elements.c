#include"header.h"
void acceptElements(int isize,int arr[])
{
    for(int i=0;i<isize;i++)
        scanf("%d",&arr[i]);
}
void DisplayArray(int isize,int arr[])
{
     for(int i=0;i<isize;i++)
        printf("%d ",arr[i]);
    printf("\n");


}
int *intersect_elements(int arr[], int m, int brr[], int n, int *intersectionSize)
{
    int i = 0, j = 0;

    int *result = NULL;
    if(m>n)
        result=malloc(sizeof(int)*m);
    else 
        result=malloc(sizeof(int)*n);
    if (result == NULL)
        return NULL;

    *intersectionSize = 0;

    while (i < m && j < n)
    {
        if (arr[i] < brr[j])
        {
            i++;
        }
        else if (arr[i] > brr[j])
        {
            j++;
        }
        else
        {
            result[*intersectionSize] = arr[i];
            (*intersectionSize)++;
            i++;
            j++;
        }
    }

    return result;
}
int main()
{
    int m=0,n=0,*arr=NULL,*brr=NULL;
    printf("Enter size of an array1\n");
    scanf("%d",&m);

    printf("Enter size of an array2\n");
    scanf("%d",&n);
    
    arr=malloc(sizeof(int)*m);
    if(arr == NULL)
    {
        printf("Memory Allocation Failed\n");
        return -1;
    }
    acceptElements(m,arr);


    brr=malloc(sizeof(int)*n);
    if(brr == NULL)
    {
        printf("Memory Allocation Failed\n");
        return -1;
    }
    acceptElements(n,brr);
    int *result=NULL,intersectionSize=m+n;

    result=intersect_elements(arr,m,brr,n,&intersectionSize);
    DisplayArray(intersectionSize,result);
    free(arr);
    free(brr);
    free(result);
    return 0;
}

/*

Version 1 (LeetCode / Striver - Unique Intersection)

Expected:

2 3

Your solution is ❌ Wrong.

Version 2 (Frequency Based Intersection)

Expected:

2 2 3

Your solution is ✅ Correct.

Interview Tip

Always ask the interviewer:

"Should the intersection contain unique elements, or should duplicates be preserved?"

That shows maturity.

If they want UNIQUE

You already know the solution!

Exactly the same check we used in Union:

if (*intersectionSize == 0 ||
    result[*intersectionSize - 1] != arr[i])
{
    result[*intersectionSize] = arr[i];
    (*intersectionSize)++;
}

Nothing else changes.
*/