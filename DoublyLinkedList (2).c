/* Doubly Linked List */
#include <stdio.h>
#include <stdlib.h>

/* Global Variable Declarations */
struct node
{
  int key;
  struct node *prev;
  struct node *next;
};

struct node *L_head = NULL; // Empty List

/* List operations */

void printList();
void PUSH(int);      // Inserting a new last element.
void POP();      // Deleting the last element.
void PEEK();  // Shows the last element in the list.
struct node *createNode(int);  // Creates a new node and initialize the key.

int main(void)
{
  char option = '\0';

  printf("------------------------\n");
  printf("Show: S\n");
  printf("PUSH: 1\n");
  printf("POP: 2\n");
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
      printf("Displaying the list\n\n");
      printList();

      break;

    case '1':
      printf("Enter the element to push in the stack: ");
      int x = 0;
      scanf("%d", &x);
      PUSH(x);

      break;

    case '2':
      
      POP();

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


void printList()
{
  /* Check whether the list is empty or not. */
  /* If not empty, create a temporary pointer which starts
     from head and navigates until there is no next node. */
  /* The terminating condition is until this temp pointer is NULL. */
  /* Update the temp pointer with the next pointer of current node. */

  if (L_head == NULL)
  {
    printf("Stack is empty\n");
  }
  else
  {
    printf("Stack elements:\n");
    struct node *tmpHead = L_head;

    while (tmpHead != NULL)
    {
      printf("[%p] ==> %p <-- %d --> %p\n",
             tmpHead, tmpHead->prev, tmpHead->key, tmpHead->next);
      tmpHead = tmpHead->next;
    }
    printf("\n");
  }

  return;
}

struct node *createNode(int x)
{
  /* malloc the new node and typecast the address to struct node ptr. */
  /* Set the key with x, prev and next to NULL */

  struct node *newNode = (struct node *)malloc(1 * sizeof(struct node));
  newNode->key = x;
  newNode->prev = NULL;
  newNode->next = NULL;

  return newNode;
}

void PUSH(int x)
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
  /* Previous pointer of the new node should point to lastNode */

  lastNode->next = newNode;
  newNode->prev = lastNode;

  return;
}

void POP()
{
  if(L_head == NULL)
  {
    printf("Error! Underflow, stack is empty. \n");
  }

  else if(L_head->next == NULL)
  {
    printf("Element that had been poped from the stack is: %d \n",L_head->key);
    L_head = NULL;
  }

  else
  {
    struct node *prevNode = NULL;
    struct node *lastNode = L_head;
       while (lastNode->next != NULL)
        {
          prevNode = lastNode;
          lastNode = lastNode->next;
        }

    printf("Element that had been poped from the stack is: %d \n",lastNode->key);    
    prevNode->next = NULL;
  }

  return ;
}

void PEEK()
{
  struct node *lastNode = L_head;
       while (lastNode->next != NULL)
        {
          lastNode = lastNode->next;
        }
  
  printf("Element at the top of the stack is : %d \n",lastNode->key);

  return;
}