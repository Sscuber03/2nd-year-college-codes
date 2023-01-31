#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int front;
    int rare;
    int size;
    int isEmpty;
    int isFull;
    int *vals;
};
void insertCqueue(int data, struct Queue *q)
{

    if (q->isFull)
        printf("Queue is Full! \n");
    else
    {
        q->rare = (q->rare + 1) % q->size;
        q->vals[q->rare] = data;
        q->isEmpty = 0;
        printf("Pushed!\n");
    }
    if (q->front == q->rare)
        q->isFull = 1;
}
void deletCqueue(struct Queue *q)
{
    if (q->isEmpty)
    {
        printf("The queue is empty!");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        printf("%d is deleted !", q->vals[q->front]);
    }
    if (q->rare == q->front)
    {
        q->front = -1;
        q->rare = -1;
    }
}
void print(struct Queue *q)
{
    int r = q->rare, f = q->front;
    if (q->front == -1 && q->rare == -1)
        printf("The queue is empty.\n");
    else
    {
        if (r <= f)
        {
            int i;
            for (i = f; i < q->size; i++)
                printf("%d ", q->vals[i]);
            for (i = r; i < f; i++)
                printf("%d ", q->vals[i]);
        }
        else
        {
            int i;
            for (i = f; i < r; i++)
                printf("%d ", q->vals[i]);
        }
    }
}
int main()
{
    struct Queue *q;
    printf("Enter size of the queue:");
    scanf("%d", &q->size);
    q->front = -1;
    q->rare = -1;
    q->isEmpty = 0;
    q->isFull = 0;
    q->vals = (int *)malloc(q->size * sizeof(int));
    printf("\nEnter 1 to insert in circuler queue\n");
    printf("Enter 2 to delete from the circuler queue\n");
    printf("Enter 3 to diplay the Queue.\n");
    printf("Enter any other number to stop the program\n");
    char c;
    int temp = 1;
    while (temp)
    {
        printf("Enter choise:");
        scanf(" %c", &c);
        if (c == '1')
        {
            printf("Enter data to insert:");
            int d;
            scanf("%d", &d);
            insertCqueue(d, q);
        }
        else if (c == '2')
        {
            deletCqueue(q);
        }
        else if (c == '3')
            print(q);
        else
        {
            temp = 0;
            printf("Your programe is sucessfully exited.\n");
        }
    }
    return 0;
}