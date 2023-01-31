#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int data;
    struct Queue *next;
};

struct Queue *head = NULL, *tail = NULL;
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
        printf("Enter element to push in queue:");
        int ele;
        scanf("%d", &ele);
        struct Queue *newnode = (struct Queue *)malloc(sizeof(struct Queue));
        newnode->data = ele;
        newnode->next = head;
        head = newnode;
        printf("Pushed !\n");
        count++;
    }
    else
        printf("Queue is Full.\n");
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
            struct Queue *temp = head;
            while (temp->next->next != NULL)
                temp = temp->next;
            printf("%d is poped\n", temp->next->data);
            free(temp->next);
            count--;
            temp->next = NULL;
        }
    }
    else
        printf("The queue is Empty!\n");
}
void top()
{
    if (!isEmpty())
    {
        struct Queue *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        printf("Top eleement = %d\n", temp->data);
    }
    else
        printf("The queue is empty.\n");
}
void print()
{
    if (!isEmpty())
    {
        struct Queue *ptr = head;
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
    else
        printf("Queue is Empty.\n");
}
void makeEmpty()
{
    if (!isEmpty())
    {
        struct Queue *ptr = head, *temp;
        while (ptr != NULL)
        {
            temp = ptr;
            ptr = ptr->next;
            free(temp);
        }
        free(ptr);
        head = NULL;
        printf("Sucessfully erased all data from queue.\n");
    }
    else
        printf("queue is already Empty.\n");
}
int main()
{
    printf("Enter the size of the queue:");
    scanf("%d", &size);
    printf("Enter '1' to push element in queue.\n");
    printf("Enter '2' to pop element from queue.\n");
    printf("Enter '3' t print the queue elements\n");
    printf("Enter '4' to print the top element of the queue.\n");
    printf("Enter '5' to check wheather queue is empty of not.\n");
    printf("Enter '6' to check wheather queue is full or not\n");
    printf("Enter '7' to make the queue empty\n");
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
                    printf("The queue is empty ? Yes\n");
                else
                    printf("The queue is empty ? No\n");
                break;
            case '6':
                if (isFull())
                    printf("The queue is Full ? Yes\n");
                else
                    printf("The queue is Full ? No\n");
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