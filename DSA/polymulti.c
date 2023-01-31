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

struct Node* multi(struct Node* h1,struct Node* h2)
{
    struct Node *head=NULL,*temp;
    while(h1!=NULL)
    {
        temp=h2;
        while(temp!=NULL)
        {
            head=insert(head,(h1->coef*temp->coef),(h1->exp+temp->exp));
            temp=temp->next;
        }
        h1=h1->next;
    }
    
    return head;
}

struct Node* modify(struct Node* head)
{
    struct Node *curr = head, *temp;
    while(curr->next!=NULL)
    {
        if(curr->exp==curr->next->exp)
        {
            curr->coef+=curr->next->coef;
            temp=curr->next;
            curr->next=temp->next;
            free(temp);
            temp=NULL;
        }
        else
        {
            curr=curr->next;
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
    printf("\nEnter Polynomial 2\n");
    struct Node *head2=NULL;
    head2=create(head2);
    print(head2);
    struct Node *head;
    head = multi(head1, head2);
    head = modify(head);
    printf("Final Polynomial after multiplication: \n");
    print(head);
}