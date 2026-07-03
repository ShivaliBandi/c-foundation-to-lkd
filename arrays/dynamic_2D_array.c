#include"header.h"
int **allocateMatrix(int irow,int icol)
{
    int **iptr=NULL;
    iptr=malloc(sizeof(int *)*irow);
    for(int i=0;i<irow;i++)
    {
        iptr[i]=malloc(sizeof(int)*icol);
    }
    return iptr;
}
void initializeMatrix(int **iptr,int irow,int icol)
{
    int count=1;
    for(int i=0;i<irow;i++)
        for(int j=0;j<icol;j++)
            iptr[i][j]=count++;
}
void printMatrix(int **iptr,int irow,int icol)
{
    for(int i=0;i<irow;i++)
    {
        for(int j=0;j<icol;j++)
            printf("[%d][%d]->%d ",i,j,iptr[i][j]);
        printf("\n");
    }
        
}
void freeMatrix(int **iptr,int irow)
{
    for(int i=0;i<irow;i++)
        free(iptr[i]);
}
int main()
{
    int **iptr=NULL;
    iptr=allocateMatrix(iptr,5,5);
    initializeMatrix(iptr,5,5);
    printMatrix(iptr,5,5);
    freeMatrix(iptr,5);
    return 0;
}