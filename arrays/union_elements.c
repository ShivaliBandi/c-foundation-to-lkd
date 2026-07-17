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
int *union_elements(int arr[], int m, int brr[], int n, int *unionSize)
{
    int i = 0, j = 0;

    int *result = malloc(sizeof(int) * (m + n));
    if (result == NULL)
        return NULL;

    *unionSize = 0;

    while (i < m && j < n)
    {
        if (arr[i] < brr[j])
        {
            if (*unionSize == 0 || result[*unionSize - 1] != arr[i])
            {
                result[*unionSize] = arr[i];
                (*unionSize)++;
            }
            i++;
        }
        else if (arr[i] > brr[j])
        {
            if (*unionSize == 0 || result[*unionSize - 1] != brr[j])
            {
                result[*unionSize] = brr[j];
                (*unionSize)++;
            }
            j++;
        }
        else
        {
            if (*unionSize == 0 || result[*unionSize - 1] != arr[i])
            {
                result[*unionSize] = arr[i];
                (*unionSize)++;
            }
            i++;
            j++;
        }
    }

    while (i < m)
    {
        if (*unionSize == 0 || result[*unionSize - 1] != arr[i])
        {
            result[*unionSize] = arr[i];
            (*unionSize)++;
        }
        i++;
    }

    while (j < n)
    {
        if (*unionSize == 0 || result[*unionSize - 1] != brr[j])
        {
            result[*unionSize] = brr[j];
            (*unionSize)++;
        }
        j++;
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
    int *result=NULL,unionSize=m+n;

    result=union_elements(arr,m,brr,n,&unionSize);
    DisplayArray(unionSize,result);
    free(arr);
    free(brr);
    free(result);
    return 0;
}