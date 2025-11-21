#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* Global Variable Declarations */
struct node
{
    char key;
    struct node *prev;
    struct node *next;
};

struct node *L_head = NULL; // Empty List

/* List operations */
void PUSH(char);
char POP();
bool isOperator(char);
int prec(char);
char* infixToPostfix(char*);

struct node *createNode(char);

int main(void)
{
    char option = '\0';

    printf("------------------------\n");
    printf("---Converts Infix to Postfix Expression---\n");
    printf("Convert Infix to Postfix: C\n");
    printf("EXIT: E\n");
    printf("------------------------\n");

    while (1)
    {

        printf("Enter your option: ");
        scanf(" %c", &option);

        switch (option)
        {
        case 'C':
            printf("Enter the Infix expression: ");
            char infix[100];
            scanf(" %[^\n]", infix);
            char* postfixExpression = infixToPostfix(infix);
            printf("Postfix expression: %s\n", postfixExpression);
            free(postfixExpression);

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

struct node *createNode(char x)
{
    struct node *newNode = (struct node *)malloc(1 * sizeof(struct node));
    newNode->key = x;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void PUSH(char x)
{
    struct node *newNode = createNode(x);

    newNode->next = L_head;
    newNode->prev = NULL;

    if (L_head != NULL)
    {
        L_head->prev = newNode;
    }
    L_head = newNode;
}

char POP()
{
    if (L_head == NULL)
    {
        printf("Stack is empty\n");
        return '\0';
    }

    char poppedElement = L_head->key;

    struct node *temp = L_head;
    L_head = L_head->next;

    if (L_head != NULL)
    {
        L_head->prev = NULL;
    }

    free(temp);

    return poppedElement;
}

bool isOperator(char c)
{
    

    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

char* infixToPostfix(char* infix)
{
    int len = strlen(infix);
    char* postfix = (char*)malloc((len + 1) * sizeof(char));
    int postfixIndex = 0;

    for (int i = 0; i < len; i++)
    {
        char c = infix[i];

        if (isOperator(c))
        {
            while (L_head != NULL && isOperator(L_head->key) && prec(L_head->key) >= prec(c))
            {
                postfix[postfixIndex++] = POP();
            }
            PUSH(c);
        }
        else if (c == '(')
        {
            PUSH(c);
        }
        else if (c == ')')
        {
            while (L_head != NULL && L_head->key != '(')
            {
                postfix[postfixIndex++] = POP();
            }
            if (L_head != NULL && L_head->key == '(')
            {
                POP();
            }
        }
        else
        {
            postfix[postfixIndex++] = c;
        }
    }

    while (L_head != NULL)
    {
        postfix[postfixIndex++] = POP();
    }

    postfix[postfixIndex] = '\0';

    return postfix;
}
