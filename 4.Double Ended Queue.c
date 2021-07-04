#include<stdio.h>
#define MAX 30

typedef struct queue
{
    int data[MAX];
    int rear,front;
}queue;

void CreateQueue(queue *p);
int isempty(queue *p);
int isfull(queue *p);
void push_front(queue *p,int x);
void push_rear(queue *p,int x);
int pop_front(queue *p);
int pop_rear(queue *p);
void display(queue *p);

int main()
{
    int i,x,Ans=0,n;
    queue q;
    CreateQueue(&q);

    printf("Enter number of elements:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter Element:",i+1);
        scanf("%d",&x);
        if(isfull(&q))
        {
            printf("Queue is isfull!!");
            break;
        }
        push_front(&q,x);
    }

    while(Ans!=6)
    {
        printf("\nThe operations that can be performed are:-\n1. Insert(rear)\n2. Insert(front)\n3. Delete(rear)\n4. Delete(front)");
        printf("\n5. Display\n6. Exit\nEnter your choice: ");
        scanf("%d",&Ans);

        switch(Ans)
        {
            case 1: printf("\nEnter element to be inserted:");
                scanf("%d",&x);

                if(isfull(&q))
                {
                    printf("\nQueue is full!!");
                    break;
                }
                push_front(&q,x);
                break;

            case 2: printf("\nEnter the element to be inserted:");
                scanf("%d",&x);

                if(isfull(&q))
                {
                    printf("\nQueue is full!!");
                    break;
                }
                push_rear(&q,x);
                break;

            case 3: if(isempty(&q))
                {
                    printf("\nQueue is empty!!");
                    break;
                }
                x=pop_rear(&q);
                printf("\nElement deleted is %d\n",x);
                break;

            case 4: if(isempty(&q))
                {
                    printf("\nQueue is empty!!");
                    break;
                }
                x=pop_front(&q);
                printf("\nElement deleted is %d\n",x);
                break;

            case 5: display(&q);
                break;

            default: break;
        }
    }
}

void CreateQueue(queue *P)
{
    P->rear=-1;
    P->front=-1;
}

int isempty(queue *P)
{
    if(P->rear==-1)
        return 1;

    return 0;
}

int isfull(queue *P)
{
    if((P->rear+1)%MAX==P->front)
        return 1;

    return 0;
}

void push_front(queue *P,int x)
{
    if(isempty(P))
    {
        P->rear=0;
        P->front=0;
        P->data[0]=x;
    }
    else
    {
        P->rear=(P->rear+1)%MAX;
        P->data[P->rear]=x;
    }
}

void push_rear(queue *P,int x)
{
    if(isempty(P))
    {
        P->rear=0;
        P->front=0;
        P->data[0]=x;
    }
    else
    {
        P->front=(P->front-1+MAX)%MAX;
        P->data[P->front]=x;
    }
}

int pop_front(queue *P)
{
    int x;

    x=P->data[P->front];

    if(P->rear==P->front)	//delete the last element
        CreateQueue(P);
    else
        P->front=(P->front+1)%MAX;

    return(x);
}

int pop_rear(queue *P)
{
    int x;

    x=P->data[P->rear];

    if(P->rear==P->front)
        CreateQueue(P);
    else
        P->rear=(P->rear-1+MAX)%MAX;

    return(x);
}

void display(queue *P)
{
    if(isempty(P))
    {
        printf("\nQueue is isempty!!");

    }

    int i;
    i=P->front;

    while(i!=P->rear)
    {
        printf("\n%d",P->data[i]);
        i=(i+1)%MAX;
    }

    printf("\n%d\n",P->data[P->rear]);
}
