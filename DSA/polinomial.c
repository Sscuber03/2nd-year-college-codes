#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int base;
    int power;
    struct Node *next;
};

void create_node(int base, int power, struct Node *head)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->base = base;
    newNode->power = power;
    newNode->next = NULL;
    if(head == NULL || head->power < power)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while(temp->next != NULL && temp->power > power)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void display(struct Node *head)
{
    struct Node *current = head;
    if(current == NULL)
        printf("The expression is empty.\n ");
    else
    {
        while(current != NULL)
        {
            printf("%dx^%d", current->base, current->power);
            current = current->next;
            if(current->next->base >= 0)
            {
                if(current->next->next != NULL)
                {
                    printf("+");
                }
            }
        }
    }
}

int main()
{
    printf("Enter the polynomial: \n");
    struct Node *poly1 = NULL;
    printf("Enter the number of terms: ");
    struct Node *temp = poly1;
    int n, base, power;
    scanf("%d", &n);
    for(int i = 0;i<n;i++)
    {
        
    }
}