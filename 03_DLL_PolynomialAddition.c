/* Doubly Linked List */
#include <stdio.h>
#include <stdlib.h>

// P1: 5x^3 + 4x^2 + 6x^1
// P2: 6x^5 + 3x^2 + 4x^1
// Result of addition, P3: 6x^5 + 5x^3 + 7x^2 + 10x^1

/* Global Variable Declarations */
struct node
{
  int coeff;
  int degree;
  struct node *prev;
  struct node *next;
};

struct node *L_head = NULL; // Empty List

/* List operations */

void printList(struct node*);
void LIST_APPEND(struct node**, int, int);      // Inserting a new last element.
struct node *createNode(int, int);  // Creates a new node and initialize the key.
void addpolys(struct node*,struct node*,struct node**);


int main(void)
{
  struct node *p_head1 = NULL;
  LIST_APPEND(&p_head1, 5, 3);
  LIST_APPEND(&p_head1, 4, 2);
  LIST_APPEND(&p_head1, 6, 1);
  
  printList(p_head1);

  struct node *p_head2 = NULL;
  LIST_APPEND(&p_head2, 6, 5);
  LIST_APPEND(&p_head2, 3, 2);
  LIST_APPEND(&p_head2, 4, 1);
  
  printList(p_head2);

  struct node *p_head3 = NULL;

  addpolys(p_head1,p_head2,&p_head3);
  printf("\n");
  printf("Addition of the two polynomials gives : \n");

  printList(p_head3);
  return 0;
}

void printList(struct node *L_head)
{
  /* Check whether the list is empty or not. */
  /* If not empty, create a temporary pointer which starts
     from head and navigates until there is no next node. */
  /* The terminating condition is until this temp pointer is NULL. */
  /* Update the temp pointer with the next pointer of current node. */

  if (L_head == NULL)
  {
    printf("List is empty\n");
  }
  else
  {
    printf("List elements:\n");
    struct node *tmpHead = L_head;

    while(tmpHead != NULL)
    {
      printf("%dx^%d ", tmpHead->coeff, tmpHead->degree);
      tmpHead = tmpHead->next;
    }
    printf("\n");
  }

  return;
}

struct node *createNode(int coeff, int degree)
{
  /* malloc the new node and typecast the address to struct node ptr. */
  /* Set the key with x, prev and next to NULL */

  struct node *newNode = (struct node *)malloc(1 * sizeof(struct node));
  newNode->coeff = coeff;
  newNode->degree = degree;
  newNode->prev = NULL;
  newNode->next = NULL;

  return newNode;
}


void LIST_APPEND(struct node **L_head, int coeff, int degree)
{
  /* Navigate to the last node and update its next pointer to link the new node. */
  /* If the list was empty, then head will point to the new node. */

  struct node *newNode = createNode(coeff, degree);

  if (*L_head == NULL)
  {
    *L_head = newNode;
    return;
  }

  /* To navigate to the last node of current list */
  struct node *lastNode = *L_head;
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

void addpolys(struct node *p_head1,struct node *p_head2,struct node **p_head3)
{
    
    
    while(p_head1 != NULL && p_head2 != NULL)
    {
      if(p_head1->degree > p_head2->degree)
      {
        LIST_APPEND(p_head3,p_head1->coeff,p_head1->degree);
        p_head1 = p_head1->next;
      }
      else if(p_head1->degree < p_head2->degree)
      {
        LIST_APPEND(p_head3,p_head2->coeff,p_head2->degree);
        p_head2 = p_head2->next;
      }
      else
      {
        LIST_APPEND(p_head3,(p_head1->coeff + p_head2->coeff),p_head1->degree);
        p_head1 = p_head1->next;
        p_head2 = p_head2->next;
      }
    }  

    if(p_head1 == NULL)
    {
      while(p_head2 != NULL)
      {
        LIST_APPEND(p_head3,p_head2->coeff,p_head2->degree);
        p_head2 = p_head2->next;
      }
    }      
    else
    {
      if(p_head2 == NULL)
      {
        while(p_head1 != NULL)
         {
           LIST_APPEND(p_head3,p_head1->coeff,p_head1->degree);
           p_head1 = p_head1->next;
         }
      }
    }     
     
  return;      
}

