#include"header.h"
void merge(int arr[],int low,int mid,int high)
{
    int i=low,j=mid+1,temp[high-low+1],k=0;
    while(i<=mid && j<=high)
    {
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
        
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= high)
        temp[k++] = arr[j++];
    for (int x = low; x <= high; x++)
        arr[x] = temp[x - low];
}
void mergeSort(int arr[],int low,int high)
{
    if(low>=high)
        return;
    int mid=low+(high-low)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

int main()
{
    int arr[10]={3,1,8,2,9,0,7,5,6,4};
    for(int i=0;i<10;i++)
        printf("%d ",arr[i]);
    printf("\n\n");
    mergeSort(arr,0,9);
    for(int i=0;i<10;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}