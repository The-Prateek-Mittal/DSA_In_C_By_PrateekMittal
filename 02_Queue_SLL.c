#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *newnode=NULL;
struct node *tail=NULL;
 struct node  *temp=NULL;
 struct node  *temp2=NULL;
void create();
void Display();
void Append();
void Delete();
int main(void){
    int option;

     printf("1------>Insert Element\n");
     printf("2------>Delete\n");
    printf("3------>Display\n");
    printf("4------>To Exit\n");
    while(1)
    
    {
    
    
    printf("Enter your Option: ");
            scanf("%d",&option);
    
        switch(option)
        {
            case 1:
            Append();
            break;
            case 2:
            Delete();
            break;
            case 3:
            Display();
            break;
            case 4:
            exit(0);
            default:
            printf("enter correct option\n");
            break;
        }
    }
    
    return 0;
}


void create()
{
newnode=(struct node*)malloc(sizeof(struct node));
newnode->next=NULL;
newnode->data=0;
}

void Display()
{  
    if(head==NULL)
    {
        printf("List is Empty\n");
    }
   else
   {
    temp=head; 
    while(temp != NULL)
    { 
        printf("%d-->%p\n",temp->data,temp->next);
        temp=temp->next;
    }
   }
    
    return;
}


void Append()
{
    create();
   printf("enter data to enter :");
   scanf("%d",&newnode->data);
   if(head== NULL)
    {
        head=newnode;
        tail=head;
    }
    else
     {    
     tail->next=newnode;
     tail=newnode;
     }
     return;
}

void Delete(int x)
{
  temp2=head;
  head=temp2->next;
  free(temp2);
}