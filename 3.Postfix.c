#include <stdio.h>
#include <ctype.h>

#define max_stack 100
#define postfixsize 100

int stack[max_stack];
int top = -1;

void push(int item);
int pop();
void evaluatepostfix(char postfix[]);

int main()
{
    int i;
    char postfix[postfixsize];
    printf(" \nEnter postfix expression,press right parenthesis ')' for end expression : ");

    for (i = 0; i <= postfixsize - 1; i++)
    {
        scanf("%c", &postfix[i]);
        if (postfix[i] == ')')
        {
            break;
        }
    }
    evaluatepostfix(postfix);
    return 0;
}

void push(int item)
{
    if (top >= max_stack - 1)
    {
        printf("stack over flow");
        return;
    }
    else
    {
        top = top + 1;
        stack[top] = item;
    }
}

int pop()
{
    int item;
    if (top < 0)
    {
        printf("stack under flow");
    }
    else
    {
        item = stack[top];
        top = top - 1;
        return item;
    }
}

void evaluatepostfix(char postfix[])
{
    int i;
    char ch;
    int val;
    int A, B;
    for (i = 0; postfix[i] != ')'; i++)
    {
        ch = postfix[i];
        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            A = pop();
            B = pop();
            switch (ch)
            {
                case '*':
                    val = B * A;
                    break;
                case '/':
                    val = B / A;
                    break;
                case '+':
                    val = B + A;
                    break;
                case '-':
                    val = B - A;
                    break;
            }
            push(val);
        }
    }
    printf("Result of expression evaluation : %d \n", pop());
}
