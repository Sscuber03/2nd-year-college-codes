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

void count()
{
    struct Node *current = head;
    int count = 0;
    while(current!=NULL)
    {
        current = current->next;
        count++;
    }
    printf("The number of elements in the linked list is: %d \n", count);
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

void reverse()
{
    struct Node *temp = NULL;
    struct Node *current = head;
    while(current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;\
        current = current->prev;
    }
    if(temp!=NULL)
    {
        tail = head;
        head = temp->prev;
    }
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