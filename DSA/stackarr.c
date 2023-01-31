#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *vals;
};

int isEmpty(struct Stack *Stack)
{
    if (Stack->top < 0)
        return 1;
    return 0;
}

int isFull(struct Stack *Stack)
{
    if (Stack->top == Stack->size - 1)
        return 1;
    return 0;
}
void push(struct Stack *Stack)
{
    int ele;
    printf("Enter element to push:");
    scanf("%d", &ele);
    Stack->top += 1;
    if (Stack->size > Stack->top)
    {
        Stack->vals[Stack->top] = ele;
        printf("Pushed !\n");
    }
    else
        printf("The stack is full , can't be pushed anymore\n");
}

void pop(struct Stack *Stack)
{
    if (!isEmpty(Stack))
    {
        Stack->top -= 1;
        Stack->size -= 1;
        printf("%d is popped \n", Stack->vals[Stack->top + 1]);
    }
    else
        printf("Stack is empty can't pop anymore\n");
}
void print(struct Stack *Stack)
{
    int i;
    if (!isEmpty(Stack))
        for (i = 0; i <= Stack->top; i++)
        {
            printf("%d ", Stack->vals[i]);
        }
    else
        printf("Stack is Empty\n");
}

void top(struct Stack *Stack)
{
    if (!isEmpty(Stack))
        printf("Top element = %d", Stack->vals[Stack->top]);
    else
        printf("The stack is Empty !\n");
}

void makeEmpty(struct Stack *Stack)
{
    if (isEmpty(Stack))
        printf("The Stack is already Empty\n");
    else
    {
        Stack->size = 0;
        Stack->top = -1;
        printf("SucessFully made the stack empty.\n");
    }
}

int main()
{
    printf("Enter the size of the stack:");
    struct Stack *Stack, s;
    Stack = &s;
    scanf("%d", &Stack->size);
    Stack->vals = (int *)malloc(Stack->size * sizeof(int));
    Stack->top = -1;
    printf("Enter '1' to push element in stack.\n");
    printf("Enter '2' to pop element from stack.\n");
    printf("Enter '3' t print the stack elements\n");
    printf("Enter '4' to print the top element of the stack.\n");
    printf("Enter '5' to check wheather stack is empty of not.\n");
    printf("Enter '6' to check wheather stack is full or not\n");
    printf("Enter '7' to make the stack empty\n");
    printf("Enter '8' to exit\n");
    char ch;
    int temp = 1;
    while (temp)
    {
        printf("\nEnter your Choice:");
        scanf(" %c", &ch);
        if (ch != '8')
        {
            switch (ch)
            {
            case '1':
                push(Stack);
                break;
            case '2':
                pop(Stack);
                break;
            case '3':
                print(Stack);
                break;
            case '4':
                top(Stack);
                break;
            case '5':
                if (isEmpty(Stack))
                    printf("The stack is empty ? Yes\n");
                else
                    printf("The stack is empty ? No\n");
                break;
            case '6':
                if (isFull(Stack))
                    printf("The stack is Full ? Yes\n");
                else
                    printf("The stack is Full ? No\n");
                break;
            case '7':
                makeEmpty(Stack);
                break;
            default:
                printf("Invalid Input.\n Try again\n");
            }
        }
        else
        {
            temp = 0;
            printf("Program Exited Sucessfully.\n");
        }
    }

    return 0;
}