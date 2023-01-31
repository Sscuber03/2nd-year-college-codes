#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int data;
    struct Stack *next;
};

struct Stack *head = NULL, *tail = NULL;
int size, count = 0;

int isEmpty()
{
    if (head == NULL)
        return 1;
    return 0;
}
int isFull()
{
    if (count == size)
        return 1;
    return 0;
}
void push()
{
    if (!isFull())
    {
        printf("Enter element to push in stack:");
        int ele;
        scanf("%d", &ele);
        struct Stack *newnode = (struct Stack *)malloc(sizeof(struct Stack));
        newnode->data = ele;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        printf("Pushed !\n");
        count++;
    }
    else
        printf("Stack is Full.\n");
}
void pop()
{
    if (!isEmpty())
    {
        if (head->next == NULL)
        {
            head = NULL;
        }
        else
        {
            struct Stack *temp = head;
            while (temp->next->next != NULL)
                temp = temp->next;
            printf("%d is poped\n", temp->next->data);
            free(temp->next);
            count--;
            temp->next = NULL;
        }
    }
    else
        printf("The stack is Empty!\n");
}
void top()
{
    if (!isEmpty())
    {
        struct Stack *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        printf("Top element = %d\n", temp->data);
    }
    else
        printf("The stack is empty.\n");
}
void print()
{
    if (!isEmpty())
    {
        struct Stack *ptr = head;
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
    else
        printf("Stack is Empty.\n");
}
void makeEmpty()
{
    if (!isEmpty())
    {
        struct Stack *ptr = head, *temp;
        while (ptr != NULL)
        {
            temp = ptr;
            ptr = ptr->next;
            free(temp);
        }
        free(ptr);
        head = NULL;
        printf("Sucessfully erased all data from stack.\n");
    }
    else
        printf("Stack is already Empty.\n");
}
int main()
{
    printf("Enter the size of the stack:");
    scanf("%d", &size);
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
                push();
                break;
            case '2':
                pop();
                break;
            case '3':
                print();
                break;
            case '4':
                top();
                break;
            case '5':
                if (isEmpty())
                    printf("The stack is empty ? Yes\n");
                else
                    printf("The stack is empty ? No\n");
                break;
            case '6':
                if (isFull())
                    printf("The stack is Full ? Yes\n");
                else
                    printf("The stack is Full ? No\n");
                break;
            case '7':
                makeEmpty();
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