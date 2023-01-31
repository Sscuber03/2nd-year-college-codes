#include <stdio.h>
#include <stdlib.h>

struct Node
{
    float coef;
    int exp;
    struct Node *next;
};

struct Node *head = NULL;

void insert(float coef, int exp)
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
}

void create()
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
            insert(coef, exp);
        }
    }
}

int main()
{
    create();
    struct Node *curr = head;
    printf("Constructed polynomial is: ");
    while(curr != NULL)
    {
        if(curr->exp > 0)
        {
            printf("%0.1fx^%d ",curr->coef,curr->exp);
        }
        else
        {
            printf("%0.1f ",curr->coef);
        }
        if(curr->next != NULL)
        {
            printf("+ ");
        }
        else
        {
            printf("\n");
        }
        curr = curr->next;
    }
    return 0;
}