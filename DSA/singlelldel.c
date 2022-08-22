#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head, *tail = NULL;

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

void delete_begin()
{
    struct Node* temp = head;
    head=head->next;
    free(temp);
}

void delete_end()
{
    struct Node* end=head;
    struct Node* prev = NULL;
    while(end->next)
    {
        prev=end;
        end=end->next;
    }
    prev->next=NULL;
    tail=prev;
    free(end);
}

void delete_at(int position)
{
    struct Node* temp;
    struct Node* prev;
    temp=head;
    prev=head;
    for(int i=0;i<position;i++)
    {
        if(i==0 && position==1)
        {
            head=head->next;
            free(temp);
        }
        else
        {
            if(i==position-1 && temp)
            {
                prev->next = temp->next;
                free(temp);
            }
            else
            {
                prev=temp;
                if(prev==NULL)
                {
                    printf("Position does not exist.");
                    break;
                }
                temp=temp->next;
            }
        }
    }
}

int main()
{
    int ch = 0, n, f = 0;
    while (f == 0)
    {
        printf("Enter 1 to delete element at top, 2 to delete element at end, 3 to delete element at position, 4 to display elements, 5 to exit the code: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            delete_begin();
            break;
        case 2:
            delete_end();
            break;
        case 3:
            printf("Enter the position to delete: ");
            scanf("%d",n);
            delete_at(n);
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