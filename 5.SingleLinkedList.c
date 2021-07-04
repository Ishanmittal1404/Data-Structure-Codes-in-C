#include <stdio.h>
#include <stdlib.h>

struct node *create(struct node*);
void display();
void insert_begin();
void insert_end();
void insert_at_pos();
void delete_begin();
void delete_end();
void delete_at_pos();
void length();
void reverse();
void search();
void sort(struct node *);
void merge(struct node*,struct node*);

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;

int main()
{
    struct node *list1;
    struct node *list2;
    int choice, option1, option2;
    int ans = 1;
    list1 = create(list1);
    while (ans)
    {
        printf("\nFollowing operation can be performed: \n1. Display\n2. Insert\n3. Delete\n4. Length\n5. Reverse\n6. Search\n7. Merge\nEnter your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                display(list1);
                break;
            case 2:
                printf("Where do you want to insert\n1]At Beginning\n2]At End\n3]At a Specified Position\nEnter your choice:");
                scanf("%d", &option1);
                switch (option1)
                {
                    case 1:
                        insert_begin();
                        break;
                    case 2:
                        insert_end();
                        break;
                    case 3:
                        insert_at_pos();
                        break;
                }
                break;
            case 3:
                printf("Where do you want to delete\n1]At Beginning\n2]At End\n3]At a Specified Position\nEnter your choice:");
                scanf("%d", &option2);
                switch (option2)
                {
                    case 1:
                        delete_begin();
                        break;
                    case 2:
                        delete_end();
                        break;
                    case 3:
                        delete_at_pos();
                        break;
                }
                break;
            case 4:
                length();
                break;
            case 5:
                reverse();
                break;
            case 6:
                search();
                break;
            case 7:
                list2 = create(list2);
                merge(list1,list2);
        }
        printf("\nDo you wish to continue:\n1. Yes\n0. No\nEnter your choice: ");
        scanf("%d",&ans);
    }
    return 0;
}

struct node *create(struct node *new)
{
    struct node *temp;
    int n, i;
    printf("Enter the numbers of nodes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        new = (struct node *) malloc (sizeof(struct node));
        printf("Enter data:");
        scanf("%d", &new->data);
        if (head == NULL)
        {
            head = new;
            new->next = NULL;
        }
        else
        {
            temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new;
            new->next = NULL;
        }
    }
    return new;
}

void display(struct node *temp)
{
    if(temp == NULL)
    {
        printf("\nList is empty");
        return;
    }
    else
    {
        temp=head;
        printf("\nThe List elements are: ");
        while(temp!=NULL)
        {
            printf("%d ",temp->data );
            temp=temp->next ;
        }
    }
}

void insert_begin()
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value to insert: ");
    scanf("%d", &new->data);

    new->next = head;
    head = new;
}

void insert_end()
{
    struct node *new;
    struct node *temp = head;

    new = (struct node *)malloc(sizeof(struct node));
    printf(("Enter the value to insert:"));
    scanf("%d", &new->data);

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->next = NULL;
}

void insert_at_pos()
{
    struct node *new;
    struct node *temp;

    int pos,i;

    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value to insert: ");
    scanf("%d",&new->data);

    printf("Enter the postion for inserting the vaue: ");
    scanf("%d", &pos);

    if(pos == 0)
    {
        new->next = head;
        head = new;
    }
    else
    {
        temp = head;
        for (i = 0; i < pos; i++)
        {
            temp = temp->next;
            if (temp->next == NULL)
            {
                break;
            }
        }
        if(temp->next == NULL)
        {
            temp->next = new;
            new->next = NULL;
        }
        else
        {
            new->next = temp->next;
            temp->next = new;
        }
    }
}

void delete_begin()
{
    struct node *temp;
    temp=head;
    head=head->next;
    printf("\nThe deleted element is :%d ",temp->data);
    free(temp);
}

void delete_end()
{

    struct node *temp;
    temp = head;

    if(temp->next == NULL)
    {
        free(temp);
        head = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void delete_at_pos()
{
    int i,pos;
    struct node *temp;
    struct node *p;
    printf("\nEnter the position of the node to be deleted: ");
    scanf("%d",&pos);
    if (pos == 0)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    else
    {
        temp = head;
        for (i = 0;i<pos;i++)
        {
            temp = temp->next;
            if (temp->next->next == NULL)
            {
                break;
            }
        }
        if (temp->next->next == NULL)
        {
            free(temp->next->next);
            temp->next = NULL;
        }
        else
        {
            p = temp->next;
            temp->next = p->next;
            free(p);
        }
    }
}

void length()
{
    int count = 0;
    struct node *temp;
    temp = head;
    while (temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("The Length of the list is:%d\n",count);
}

void reverse()
{
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;

}

void search()
{
    int value,flag;
    printf("Enter the value to be searched: ");
    scanf("%d",&value);
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        if (value == temp->data)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
        temp = temp->next;
    }
    if(flag==1)
    {
        printf("%d is present in the list\n",value);
    }
    else
    {
        printf("%d is not present in the list\n",value );
    }
}

void sort(struct node *list)
{
    struct node *start;
    start = head;
    int s,temp;
    struct node *ptr1;
    struct node *ptr = NULL;
    if (start == NULL)
    {
        return;
    }
    do
    {
        s = 0;
        ptr1 = start;
        while (ptr1->next != ptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data= temp;
                s = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr = ptr1;
    }
    while (s);
}

void merge(struct node* l1,struct node* l2)
{
    struct  node *l3;
    struct node *ptr3;
    struct node *temp;
    ptr3 = NULL;
    struct node *ptr;
    ptr = l1;
    struct node *ptr2;
    ptr2 = l2;
    while(ptr!=NULL &&ptr2!=NULL)
    {
        temp=(struct node*)malloc(sizeof(struct node*));
        temp->next=NULL;
        if(ptr->data<ptr2->data)
        {
            temp->data=ptr->data;
            ptr=ptr->next;
        }
        else if(ptr->data>ptr2->data)
        {
            temp->data=ptr2->data;
            ptr2=ptr2->next;
        }
        else if(ptr->data==ptr2->data)
        {
            temp->data=ptr->data;
            ptr=ptr->next;
            ptr2=ptr2->next;
        }
        if(ptr3==NULL)
        {
            ptr3=temp;
            l3=temp;
        }
        else{
            ptr3->next=temp;
            ptr3=temp;
        }
    }
    while(ptr!=NULL)
    {
        temp =(struct node*)malloc(sizeof(struct node*));
        temp->next=NULL;
        temp->data=ptr->data;
        ptr3->next=temp;
        ptr3=temp;
        ptr=ptr->next;
    }
    while(ptr2!=NULL)
    {
        temp=(struct node*)malloc(sizeof(struct node*));
        temp->next=NULL;
        temp->data=ptr2->data;
        ptr3->next=temp;
        ptr3=temp;
        ptr2=ptr2->next;
    }
    display(l3);
    printf("\nAfter Sorting: ");
    sort(l3);
    display(l3);
}
