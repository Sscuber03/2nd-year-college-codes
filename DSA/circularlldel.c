#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL, *tail = NULL;

void addNode(int data)
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

void delete_front()
{
    struct Node *temp;
    if(tail == NULL)
        printf("List is empty. \n");
    else
    {
        temp = tail->next;
        tail->next = temp->next;
        head = tail->next;
        free(temp);
    }
}

void delete_end()
{
    if(tail == NULL)
        printf("List is empty. \n");
    struct Node *temp = head;
    while(temp->next != tail)
        temp = temp->next;
    temp->next = tail->next;
    tail = temp;
}

void delete_at(int position)
{
    struct Node *current = head, *temp;
    for(int i = 1;i<position-1;i++)
    {
        current = current->next;
    }
    temp = current->next;
    current->next = current->next->next;
    free(temp);
}

int main()
{
    int ch = 0, n, p, f = 0, ff = 0;
    while (f == 0)
    {
        if(ff == 0)
        {
            printf("Enter 1 to add element, 2 delete element from front, 3 to delete element from back, 4 to delete element at position, 5 to display the list, 6 to exit the code: ");
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
            scanf("%d", &p);
            delete_at(p);
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