#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL, *tail = NULL;

void addNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

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

void delete_end()
{
    struct Node *temp = tail;
    tail = tail->prev;
    tail->next=NULL;
    free(temp);
}

void delete_front()
{
    struct Node *temp = head;
    head = head->next;
    head->prev=NULL;
    free(temp);
}

void delete_at(int n)
{
    struct Node *current = head;
    for(int i=0;i<n;i++)
    {
        current = current->next;
    }
    struct Node *prev = current->prev;
    struct Node *next = current->next;
    prev->next=next;
    next->prev=prev;
    free(current);
}

int main()
{
    int ch = 0, n, f = 0;
    while (f == 0)
    {
        printf("Enter 1 to add element, 2 delete element from front, 3 to delete element from back, 4 to delete element at position,5 to display the list, 6 to exit the code: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to enter: ");
            scanf("%d", &n);
            addNode(n);
            break;
        case 2:
            delete_front();
            break;
        case 3:
            delete_end();
            break;
        case 4:
            printf("Enter the position to delete: ");
            scanf("%d", &n);
            delete_at(n);
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