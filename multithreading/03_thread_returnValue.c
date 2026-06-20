#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char name[10];
    int id;
    int marks;
};

void *student(void *args)
{
    struct node *s=(struct node *)args;
    printf("inside student function\nname: %s\tid: %d\tmarks: %d\n",s->name,s->id,s->marks);

    s->id=10;
    s->marks=200;
    return s;
    
}
int main()
{
    struct node *nobj=NULL;
    struct node *nptr=NULL;
    nobj=(struct node *)malloc(sizeof(struct node));
    nobj->id=1;
    strcpy(nobj->name,"Shivali");
    nobj->marks=100;
    pthread_t threadId;
    pthread_create(&threadId,NULL,student,nobj);
    pthread_join(threadId,(void **)&nptr);
    printf("\ninside main function\nname: %s\tid: %d\tmarks: %d\n",nptr->name,nptr->id,nptr->marks);

    
    return 0;
}