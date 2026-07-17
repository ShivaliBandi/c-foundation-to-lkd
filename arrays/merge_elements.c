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
int *merge_elements(int arr[], int m, int brr[], int n)
{
    int i = 0, j = 0;

    int *result = malloc(sizeof(int) * (m + n)),mergeSize=0;
    if (result == NULL)
        return NULL;
    
    while (i < m && j < n)
    {
        if (arr[i] < brr[j])
            result[mergeSize++] = arr[i++];
        else if (arr[i] > brr[j])
            result[mergeSize++] = brr[j++];
            
        else
        {
            result[mergeSize++] = brr[j++];
            result[mergeSize++] = arr[i++];
        }   
    }

    while (i < m)
        result[mergeSize++] = arr[i++];
        

    while (j < n) 
        result[mergeSize++] = brr[j++];


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
    int *result=NULL;

    result=merge_elements(arr,m,brr,n);
    DisplayArray(m+n,result);
    free(arr);
    free(brr);
    free(result);
    return 0;
}