#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head, *tail = NULL;

void addNode(int data)
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

void count()
{
    struct Node *current = head;
    int count = 0;
    while (current != NULL)
    {
        current = current->next;
        count++;
    }
    printf("Number of Nodes in the link list is: %d \n", count);
}

void reverse()
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    printf("The list is reversed! \n");
}

int main()
{
    int ch = 0, n, f = 0;
    while (f == 0)
    {
        printf("Enter 1 to add element, 2 to display count of elements, 3 to display the elements, 4 to reverse the elements, 5 to exit the code: ");
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