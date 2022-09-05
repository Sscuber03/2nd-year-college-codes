#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL, *tail = NULL;

void insert_front(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;
    if(head != NULL)
        head->prev = newNode;
    head = newNode;
}

void insert_end(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL)
    {
        newNode->prev=NULL;
        head=newNode;
    }
    else
    {
        tail->next=newNode;
        newNode->prev=tail;
    }
    tail=newNode;
}

int main()
{
    int ch = 0, n, f = 0;
    while (f == 0)
    {
        printf("Enter 1 to add element at front, 2 to add elements at end, 3 to display the elements, 4 to exit the code: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to enter: ");
            scanf("%d", &n);
            insert_front(n);
            break;
        case 2:
            printf("Enter the element to enter: ");
            scanf("%d", &n);
            insert_end(n);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting code execution...");
            f = 1;
            break;
        default:
            printf("Wrong choice!!");
        }
    }
    return 0;
}