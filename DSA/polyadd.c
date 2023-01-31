#include <stdio.h>
#include <stdlib.h>

struct Node
{
    float coef;
    int exp;
    struct Node *next;
};

struct Node* insert(struct Node* head, float coef, int exp)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    if(head==NULL || head->exp < exp)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        struct Node *curr = head;
        while(curr->next != NULL && curr->next->exp > exp)
        {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
    return head;
}

struct Node* create(struct Node* head)
{
    int n, t, exp;
    float coef;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);
    t = n;
    while(n--)
    {
        printf("Enter the cofficient of term %d :",t-n);
        scanf("%f",&coef);
        printf("Enter the exponenet of term %d :",t-n);
        scanf("%d",&exp);
        if(coef > 0)
        {
            head = insert(head, coef, exp);
        }
    }
    return head;
}

struct Node* sum(struct Node* h1, struct Node* h2)
{
    struct Node* head = NULL;
    while(h1!=NULL || h2!=NULL)
    {
        if((h1!=NULL && h2!=NULL) && (h1->exp == h2->exp))
        {
            head = insert(head, (h1->coef+h2->coef),h1->exp);
            h1=h1->next;
            h2=h2->next;
        }
        else
        {
            if(h1!=NULL)
            {
                head = insert(head, h1->coef,h1->exp);
                h1=h1->next;
            }
            else if(h2!=NULL)
            {
                head = insert(head, h2->coef,h2->exp);
                h2=h2->next;
            }
        }
    }
    return head;
}

void print(struct Node* head)
{
    struct Node*temp=head;
    while(temp!=NULL)
    {
        if(temp->exp > 0)
            printf("%0.1fx^%d ",temp->coef,temp->exp);
        else
            printf("%0.1f ",temp->coef);
        if(temp->next!=NULL && temp->next->coef>0)
            printf("+ ");
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    printf("Enter Polynomial 1\n");
    struct Node *head1=NULL;
    head1=create(head1);
    print(head1);
    printf("Enter Polynomial 2\n");
    struct Node *head2=NULL;
    head2=create(head2);
    print(head2);
    struct Node *head;
    head=sum(head1,head2);
    printf("Final Polynomial after addition is: \n");
    print(head);
    return 0;
}