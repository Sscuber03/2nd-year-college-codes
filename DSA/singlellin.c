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
    struct Node *current = head;
    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        printf("The Nodes of the list are: ");
        while (current != NULL)
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
    head = newNode;
    if(tail == NULL)
        tail = newNode;
}

void insert_end(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void insert_after(int position, int data)
{
    struct Node *prev=head;
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
        if(tail->next != NULL)
            tail = newNode;
    }
}

int main()
{
    int ch = 0, n, f = 0,p;
    while (f == 0)
    {
        printf("Enter 1 to add element at front, 2 to add element at end, 3 to add element after a node, 4 display the list, 5 to exit the code: ");
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
            display();
            break;
        case 5:
            printf("Exiting code execution...");
            f = 1;
            break;
        default:
            printf("Wrong choice!!");
        }
    }
    return 0;
}