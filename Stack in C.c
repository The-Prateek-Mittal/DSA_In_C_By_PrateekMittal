/* Stack Implementation using Arrays */
#include <stdio.h>
#include <stdlib.h>

/* Global Variable Declarations */

int S_size = 5;
int S_top = -1;

/* Stack operations */
void display(int[]);
void PUSH(int[], int);
int POP(int[]);
int STACK_EMPTY(int[]);
void PEEK(int[]);

int main(void)
{
    int S[5] = {0};
    int x = 0;

    char option = '\0';

    printf("-----------------\n");
    printf("---STACK  Menu---\n");
    printf("Show: S\n");
    printf("PUSH: I\n");
    printf("POP : D\n");
    printf("PEEK : L\n");
    printf("EXIT: E\n");
    printf("-----------------\n");

    while (1)
    {

        printf("Enter your option: ");
        scanf(" %c", &option);

        switch (option)
        {
        case 'S':
            printf("Displaying Stack\n\n");
            display(S);

            break;

        case 'I':
            printf("Enter element to insert:");
            scanf("%d", &x);
            PUSH(S, x);

            break;

        case 'D':
            x = POP(S);

            break;

        case 'L':
            PEEK(S);
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

void display(int S[])
{
    
    if(STACK_EMPTY(S))
    {
        printf("Stack is empty. \n");
    }
    else
    {
        printf("{ ");
        for(int i = 0; i<=S_top;i++)
        {
            printf("%d ",S[i]);
        }
        printf("} \n");
    }


}

void PUSH(int S[], int x)
{
        if(S_top==(S_size-1))
    {
        printf("Error! Stack Overflow. \n");
    }
    else
    {
        S_top = S_top + 1;
        S[S_top] = x;

    }
    
}

int STACK_EMPTY(int S[])
{
    if(S_top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int POP(int S[])
{
    
    if(STACK_EMPTY(S))
    {
        printf("Error! Stack Underflow. \n");
    }
    else
    {
        S_top = S_top - 1;
    }

}

void PEEK(int S[])
{
   
    if(STACK_EMPTY(S))
    {
        printf("Stack is empty. \n");
    }
    else
    {
        printf("Element presesent at the top : %d \n",S[S_top]);
    }
  
}
