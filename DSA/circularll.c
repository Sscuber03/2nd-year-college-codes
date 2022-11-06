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

void count()
{
    int count = 0;
    struct Node *current;
    current = head;
    if(current == NULL)
    {
        printf("Number of Nodes in the link list is: %d \n", count);
    }
    else
    {
        do
        {
            count++;
            current = current->next;
        }while(current != head);
        printf("Number of Nodes in the link list is: %d \n", count);
    }
}

void reverse()
{
    if(head == NULL)
        printf("The list is empty.");
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;
    do
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);
    head->next = prev;
    tail = head;
    head = prev;
    printf("The list is reversed! \n");
}

int main()
{
    int ch = 0, n, f = 0, ff = 0;
    while (f == 0)
    {
        if(ff == 0)
        {
            printf("Enter 1 to add element, 2 to display count of elements, 3 to display the elements, 4 to reverse the elements, 5 to exit the code: ");
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
            count();
            break;
        case 3:
            display();
            break;
        case 4:
            reverse();
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