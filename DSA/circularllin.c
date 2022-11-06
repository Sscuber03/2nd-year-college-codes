#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL, *tail = NULL;

void display()
{
    struct Node *current;
    current = head;
    if(current == NULL)
    {
        printf("The list is empty. \n");
    }
    else
    {
        printf("The Nodes of the list are: ");
        do
        {
            printf("%d ", current->data);
            current = current->next;
        }while(current != head);
        printf("\n");
    }
}

void insert_end(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if(tail == NULL)
    {
        newNode->data = data;
        newNode->next = newNode;
        tail = newNode;
        head = newNode;
    }
    else
    {
        newNode->data = data;
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

void insert_front(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if(tail == NULL)
    {
        newNode->data = data;
        newNode->next = newNode;
        tail = newNode;
        head = newNode;
    }
    else
    {
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
}

void insert_after(int position, int data)
{
    struct Node *prev = head;
    if(prev == NULL)
        insert_end(data);
    for(int i=0;i<position-1;i++)
    {
        prev = prev->next;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=prev->next;
    prev->next=newNode;
    if(tail->next != head)
        tail = newNode;
}

void insert_before(int position, int data)
{
    insert_after(position-1, data);
}

int main()
{
    int ch = 0, n, f = 0,p, ff = 0;
    while (f == 0)
    {
        if(ff == 0)
        {
            printf("Enter 1 to add element at front, 2 to add element at end, 3 to add element after a position, 4 to add element before a position, 5 display the list, 6 to exit the code: ");
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
            printf("Enter the element to enter: ");
            scanf("%d", &n);
            printf("Enter the position after which the element is to be entered: ");
            scanf("%d",&p);
            insert_after(p,n);
            break;
        case 4:
            printf("Enter the element to enter: ");
            scanf("%d", &n);
            printf("Enter the position before which the element is to be entered: ");
            scanf("%d",&p);
            insert_before(p,n);
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