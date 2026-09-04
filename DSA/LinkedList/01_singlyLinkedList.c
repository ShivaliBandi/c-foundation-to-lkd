#include"header.h"
struct Node{
    int data;
    struct Node* next;
};
/*
struct Node **head
head       → address of caller's head
*head      → actual head pointer
newNode    → temporary pointer used to walk through the list
*/
struct Node* createNode(int data)
{
    struct Node* newNode=NULL;
    newNode=malloc(sizeof(struct Node));
    if(newNode==NULL)
    {
        perror("ERROR:");
        return NULL;
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;

}
bool insertFirst(struct Node **head,int data)
{
    struct Node* newnode=createNode(data);
    if(newnode==NULL)
    {
        perror("ERROR:");
        return false;
    }
    if(*head==NULL)
    {
        *head=newnode;
        return true;
    }
    else
    {
        newnode->next=*head;
        *head=newnode;
        return true;
    }

}
int count(struct Node* head)
{
    int icount=0;
    while(head!=NULL)
    {
        icount++;
        head=head->next;
    }
    return icount;
}

bool insertLast(struct Node **head,int data)
{
    struct Node* newnode=createNode(data);
    if(newnode==NULL)
    {
        perror("ERROR:");
        return false;
    }
    if(*head==NULL)
    {
        *head=newnode;
        return true;
    }
    else
    {
        struct Node *temp=*head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
        return true;
    }
}

bool insertAt(struct Node** head,int ipos,int data)
{
   
   
    
    int icount=count(*head);
    if ((ipos>0) && (ipos<=(icount+1)))
    {
        
        if(ipos==1)
            insertFirst(head,data);
        else if(ipos==(icount+1))
            insertLast(head,data);
        else
        {
            struct Node* newnode=createNode(data);
            if(newnode==NULL)
            {
                perror("ERROR:");
                return false;
            }
            struct Node *temp=*head;
            while(ipos!=2)
            {
                temp=temp->next;
                ipos--;
            }
                
            newnode->next=temp->next;
            temp->next=newnode;
            return true;
        }
    }
    return false;
    
}

void displayLinkedlist(struct Node *head)
{
    if(head==NULL)
        printf("Linkedlist is empty\n");
    else
    {
        while(head!=NULL)
        {
            printf("%d->",head->data);
            head=head->next;
        }
        printf("NULL\n");
    }
}
bool deleteFirst(struct Node** head)
{
    if(*head==NULL)
    {
        printf("Linkedlist is empty\n");
        return false;
    }
    else
    {
        struct Node *temp=*head;
        (*head)=(*head)->next;
        free(temp);
        return true;
    }
}
bool deleteLast(struct Node **head)
{
    if(*head==NULL)
    {
        printf("Linkedlist is empty\n");
        return false;
    }
    else if((*head)->next==NULL)
    {
        free((*head));
        *head=NULL;
    }
    
    else
    {
        struct Node *temp=*head;
        while (temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        struct Node *cur=temp;
        cur=cur->next;
        temp->next=NULL;
        free(cur);
        
        
    }
    return true;
}

bool deleteAt(struct Node **head, int ipos)
{
    
     
        int icnt= count(*head);

        if(ipos>0 && ipos<=icnt)
        {
            if(((*head)==NULL))
            {
                printf("Linkedlist is empty");
                return false;
            }
            if(ipos==1)
                deleteFirst(head);
            else if(ipos==icnt)
                deleteLast(head);
            else
            {
                struct Node* curr=(*head);
                struct Node* temp=(*head);
                while(ipos!=2)
                {
                    curr=curr->next;
                    ipos--;
                }
                temp=curr->next;
                curr->next=temp->next;
                free(temp);
                return true;
            }
           
        }

        
    
    return false;
}
int main()
{
    struct Node *head=NULL;
    bool returnValue=insertLast(&head,10);
    if(!returnValue==false)
        printf("value intserted successfully\n");
    

    returnValue=insertLast(&head,20);
    if(!returnValue==false)
        printf("value intserted successfully\n");
    
    returnValue=insertLast(&head,30);
    if(!returnValue==false)
        printf("value intserted successfully\n");
    
    returnValue=insertLast(&head,50);
    if(!returnValue==false)
        printf("value intserted successfully\n");
    displayLinkedlist(head);

//////////////////////////////////////////////////////////////////////////////////////////////

    returnValue=insertFirst(&head,60);
    if(!returnValue==false)
        printf("value intserted successfully\n");
    
    returnValue=insertFirst(&head,70);
    if(!returnValue==false)
        printf("value intserted successfully\n");
    
    returnValue=insertFirst(&head,80);
    if(!returnValue==false)
        printf("value intserted successfully\n");
    displayLinkedlist(head);

///////////////////////////////////////////////////////////////////////////////////////////////////

    returnValue=insertAt(&head,3,600);
        if(!returnValue==false)
            printf("value intserted successfully\n");
        
        returnValue=insertAt(&head,4,700);
        if(!returnValue==false)
            printf("value intserted successfully\n");
    
    returnValue=insertAt(&head,count(head)+1,800);
    if(!returnValue==false)
        printf("value intserted successfully\n");
    displayLinkedlist(head);
//////////////////////////////////////////////////////////////////////////////////////////////////
    //delete first
    returnValue=deleteFirst(&head);
    displayLinkedlist(head);

//////////////////////////////////////////////////////////////////////////////////////////////////
    returnValue=deleteLast(&head);
    displayLinkedlist(head);
//////////////////////////////////////////////////////////////////////////////////////////////////
    returnValue=deleteAt(&head,1);
    displayLinkedlist(head);
     returnValue=deleteAt(&head,count(head));
    displayLinkedlist(head);
     returnValue=deleteAt(&head,0);
    displayLinkedlist(head);
     returnValue=deleteAt(&head,5);
    displayLinkedlist(head);
     returnValue=deleteAt(&head,10);
    displayLinkedlist(head);


//////////////////////////////////////////////////////////////////////////////////////////////////

    struct Node *temp = head;
    struct Node *next;
    while (temp != NULL)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }

    head = NULL;    
    return 0;
}