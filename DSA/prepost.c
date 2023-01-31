#include <stdio.h>
#include <stdio.h>
#include <string.h>

int top = -1;

int isEmpty()
{
    if (top == -1)
        return 1;
    return 0;
}

void push(char *stack, char c)
{
    top++;
    stack[top] = c;
}

void pop()
{
    top--;
}

int priority(char a)
{
    switch (a)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    case '$':
        return 4;
    }
    return 1;
}

int isOperater(char a)
{
    switch (a)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '$':
        return 1;
    default:
        return 0;
    }
    return 0;
}

int isOperand(char a)
{
    if ((a >= 48 && a <= 57) || (a >= 65 && a <= 91) || (a >= 97 && a <= 121))
        return 1;
    return 0;
}

char *makePostfix(char I[100], char P[100])
{
    char stack[100];
    int i = 0, j = 0;
    while (I[i] != '\0')
    {
        if (isOperand(I[i]))
        {
            P[j] = I[i];
            j++;
        }
        else if (isOperater(I[i]))
        {
            while (!isEmpty() && stack[top] != '(' && priority((stack[top])) >= priority(I[i]))
            {
                P[j] = stack[top];
                pop();
                j++;
            }
            push(stack, I[i]);
        }
        else if (I[i] == '(')
        {
            push(stack, I[i]);
        }
        else
        {
            while (stack[top] != '(')
            {
                P[j] = stack[top];
                pop();
                j++;
            }
            pop();
        }
        i++;
    }
    while (top != -1)
    {
        P[j] = stack[top];
        pop();
        j++;
    }
    return (char *)P;
}

void reverse(char *s)
{
    int i = 0, j = strlen(s) - 1;
    char temp;
    while (i < j)
    {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
        if (s[j] == '(')
            s[j] = ')';
        else if (s[j] == ')')
            s[j] = '(';
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

void makePrefix(char *I)
{
    reverse(I);
    char *pre, P[100];
    pre = makePostfix(I, P);
    reverse(pre);
    printf("The prefix of the given infix is = %s\n", pre);
}

int main()
{
    char ch[100], P[100];
    printf("Enter one infix equation:");
    scanf(" %s", ch);
    printf("The postfix of the given infix is = %s\n", makePostfix(ch, P));
    makePrefix(ch);
    return 0;
}
