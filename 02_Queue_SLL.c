/* Implementation of Queue using Singly Linked list  */
#include <stdio.h>
#include <stdlib.h>

/* Global Variable Declarations */
struct node
{
  int key;
  struct node *next;
};

struct node *L_head = NULL; // Empty List

/* List operations */

void printList();
void ENQUEUE(int); 
void DEQUEUE(); 
void PEEK(); 
struct node *createNode(int);

int main(void)
{
  char option = '\0';

  printf("------------------------\n");
  printf("---Queue---\n");
  printf("Show: S\n");
  printf("ENQUEUE: 1\n");
  printf("DEQUEUE: 2\n");
  printf("PEEK: 3\n");
  printf("EXIT: E\n");
  printf("------------------------\n");

  while (1)
  {

    printf("Enter your option: ");
    scanf(" %c", &option);

    switch (option)
    {
    case 'S':
      printf("Displaying the queue.\n");
      printList();

      break;

    case '1':
      printf("Enter the element to enqueue: ");
      int x = 0;
      scanf("%d", &x);
      ENQUEUE(x);

      break;

    case '2':
      
      DEQUEUE();

      break;

    case '3':
      PEEK();
      break;

    
    case 'E':
      printf("Exit\n\n");
      exit(0);

    default:
      printf("Enter correct option\n\n");
    }
  }

  return 0;
}

struct node *createNode(int x)
{
  /* malloc the new node and typecast the address to struct node ptr. */
  /* Set the key with x, prev and next to NULL */

  struct node *newNode = (struct node *)malloc(1 * sizeof(struct node));
  newNode->key = x;
  newNode->next = NULL;

  return newNode;
}

void printList()
{
  
  if (L_head == NULL)
  {
    printf("Queue is empty\n");
  }
  else
  {
    printf("Queue elements:\n");
    struct node *tmpHead = L_head;

    while (tmpHead != NULL)
    {
      printf("[%p] ==>  %d ----> %p\n",
             tmpHead, tmpHead->key, tmpHead->next);
      tmpHead = tmpHead->next;
    }
    printf("\n");
  }

  return;
}

void ENQUEUE(int x)
{
    /* Navigate to the last node and update its next pointer to link the new node. */
  /* If the list was empty, then head will point to the new node. */

  struct node *newNode = createNode(x);

  if (L_head == NULL)
  {
    L_head = newNode;
    return;
  }

  /* To navigate to the last node of current list */
  struct node *lastNode = L_head;
  while (lastNode->next != NULL)
  {
    lastNode = lastNode->next;
  }

  /* Next pointer of lastNode should point to the new node. */

  lastNode->next = newNode;

  return;
}

void DEQUEUE()
{
    if(L_head == NULL)
    {
        printf("Error! Underflow, Queue is empty. \n");
    }
    else if((L_head->next) == NULL)
    {
        printf("Element that had been dequeued is: %d \n",L_head->key);
        L_head = NULL;
    }
    else
    {
       printf("Element that had been dequeued is: %d \n",L_head->key);
       L_head = L_head->next;
    }
    return;
}

void PEEK()
{
    printf("The element in the front is: %d \n",L_head->key);
    return;
}



