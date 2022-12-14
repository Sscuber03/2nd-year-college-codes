#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL, *tail = NULL;

void display()
{
    struct Node *current = head;
    if(head==NULL)
        printf("The list is empty.");
    else
    {
        printf("The nodes of the list are: \n");
        while(current!=NULL)
        {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

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

void insert_after(int position, int data)
{
    struct Node *prev = head;
    for(int i=0;i<position-1;i++)
    {
        if(prev==NULL)
        {
            break;
        }
        prev = prev->next;
    }
    if(prev==NULL)
    {
        printf("That position does not exist.\n ");
    }
    else
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data=data;
        newNode->next=prev->next;
        prev->next=newNode;
        newNode->next->prev = newNode;
        newNode->prev = prev;
        if(tail->next != NULL)
            tail = newNode;
    }
}

void insert_before(int position, int data)
{
    insert_after(position-1, data);
}

int main()
{
    int ch = 0, n, p, f = 0, ff = 0;
    while (f == 0)
    {
        if(ff == 0)
        {
            printf("Enter 1 to add element at front, 2 to add elements at end, 3 to add elements after a position, 4 to insert element before a position, 5 to display the elements, 6 to exit the code: ");
            ff = 1;
        }
        else
        {
            printf("Enter your choice: ");
        }
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
            printf("Enter the position to enter: ");
            scanf("%d", &p);
            printf("Enter the element to enter: ");
            scanf("%d", &n);
            insert_after(p, n);
            break;
        case 4:
            printf("Enter the position to enter: ");
            scanf("%d", &p);
            printf("Enter the element to enter: ");
            scanf("%d", &n);
            insert_before(p, n);
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exiting code execution...");
            f = 1;
            break;
        default:
            printf("Wrong choice!!");
        }
    }
    return 0;
}