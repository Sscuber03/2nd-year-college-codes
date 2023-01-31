#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int count;
    int *val;
};

int count = -1;

int isEmpty(struct Queue *Queue)
{
    if (Queue->count < 0)
        return 1;
    return 0;
}

int isFull(struct Queue *Queue)
{
    if (Queue->size - 1 == Queue->count)
        return 1;
    return 0;
}

void push(struct Queue *Queue)
{
    int ele;
    printf("Enter element to push:");
    scanf("%d", &ele);

    if (Queue->size > Queue->count + 1)
    {
        Queue->count += 1;
        Queue->val[Queue->count] = ele;
        printf("Pushed !\n");
    }
    else
        printf("The queue is full , can't be pushed anymore\n");
}

void pop(struct Queue *Queue)
{
    int temp = Queue->val[0];
    if (!isEmpty(Queue))
    {

        if (Queue->count == 0)
            Queue->count--;
        else
        {
            int i = 0;
            while (i < Queue->count)
            {
                Queue->val[i] = Queue->val[i + 1];
                i++;
            }
            Queue->count--;
        }
        printf("%d is popped \n", temp);
    }
    else
        printf("Queue is empty can't pop anymore\n");
}

void print(struct Queue *Queue)
{
    int i;
    if (!isEmpty(Queue))
        for (i = Queue->count; i >= 0; i--)
        {
            printf("%d ", Queue->val[i]);
        }
    else
        printf("Queue is Empty\n");
}

void top(struct Queue *Queue)
{
    if (!isEmpty(Queue))
        printf("Top element = %d", Queue->val[0]);
    else
        printf("The queue is Empty !\n");
}

void makeEmpty(struct Queue *Queue)
{
    if (isEmpty(Queue))
        printf("The queue is already Empty\n");
    else
    {
        Queue->size = 0;
        Queue->count = -1;
        printf("SucessFully made the queue empty.\n");
    }
}

int main()
{
    printf("Enter the size of the queue:");
    struct Queue *Queue;
    scanf("%d", &Queue->size);
    Queue->val = (int *)malloc(Queue->size * sizeof(int));
    Queue->count = -1;
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
                push(Queue);
                break;
            case '2':
                pop(Queue);
                break;
            case '3':
                print(Queue);
                break;
            case '4':
                top(Queue);
                break;
            case '5':
                if (isEmpty(Queue))
                    printf("The queue is empty ? Yes\n");
                else
                    printf("The queue is empty ? No\n");
                break;
            case '6':
                if (isFull(Queue))
                    printf("The queue is Full ? Yes\n");
                else
                    printf("The queue is Full ? No\n");
                break;
            case '7':
                makeEmpty(Queue);
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