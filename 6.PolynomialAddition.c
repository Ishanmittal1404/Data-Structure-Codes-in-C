#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coeff;
    int pow;
    struct node *next;
};
void create(struct node *);
void display(struct node *);
void polyadd(struct node *,struct node *,struct node *);

int main()
{
    struct node* poly1;
    struct node* poly2;
    struct node* poly;
    poly1=(struct node *)malloc(sizeof(struct node));
    poly2=(struct node *)malloc(sizeof(struct node));
    poly=(struct node *)malloc(sizeof(struct node));
    printf("First Polynomial:");
    create(poly1);
    printf("The First Polynomial is");
    display(poly1);
    printf("\n\nSecond Polynomial:");
    create(poly2);
    printf("The Second Polynomial is:");
    display(poly2);
    polyadd(poly1,poly2,poly);
    printf("\n\nThe Added Polynomial is:");
    display(poly);
    return 0;
}

void create(struct node *temp)
{
    int ans = 1;
    while(ans == 1)
    {
        printf("\nEnter the Coeffecient of the term: ");
        scanf("%d",&temp->coeff);
        printf("Enter the Power of the term: ");
        scanf("%d",&temp->pow);
        temp->next=(struct node*)malloc(sizeof(struct node));
        temp=temp->next;
        temp->next=NULL;
        printf("Do you want to continue:\n1. Yes\n0. No\nEnter your Choice: ");
        scanf("%d",&ans);
    }
}
void display(struct node *temp)
{
    while(temp->next!=NULL)
    {
        printf("%dx^%d",temp->coeff,temp->pow);
        temp=temp->next;
        if(temp->next!=NULL)
        {
            printf("+");
        }
    }
}

void polyadd(struct node *poly1,struct node *poly2,struct node *poly)
{
    while(poly1->next &&  poly2->next)
    {
        if(poly1->pow > poly2->pow)
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        else
        {
            if(poly1->pow < poly2->pow)
            {
                poly->pow = poly2->pow;
                poly->coeff = poly2->coeff;
                poly2 = poly2->next;
            }
            else
            {
                poly->pow = poly1->pow;
                poly->coeff = poly1->coeff+poly2->coeff;
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
        }
        poly->next = (struct node *)malloc(sizeof(struct node));
        poly = poly->next;
        poly->next = NULL;
    }

    while(poly1->next || poly2->next)
    {
        if(poly1->next)
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if(poly2->next)
        {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        poly->next = (struct node *)malloc(sizeof(struct node));
        poly = poly->next;
        poly->next = NULL;
    }
}
