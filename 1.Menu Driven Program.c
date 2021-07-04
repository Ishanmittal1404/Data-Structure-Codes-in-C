/* Create an array and implement the operations – traverse(), insert_element(), delete_element(), sort(),search(),
 * merge(), copy(), create(), isFull(), isEmpty(), length() and resize().Write a C program to demonstrate an array ADT
 * using defined operations appropriately using a menu-driven approach. Your program should be able to print the array
 * contents appropriately at any or all instances(as  required  may  be).  */
#include <stdio.h>
int max_len = 100;


void tranverse(int x[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\n", x[i]);
    }
}
int* insert_element(int x[],int n,int element_add,int element_pos)
{
    for (int i = n; i >= element_pos; i--)
    {
        x[i] = x[i - 1];
    }
    x[element_pos - 1] = element_add;
    return x;
}

int* delete_element(int x[],int n,int delete_element_pos)
{
    for (int i = delete_element_pos - 1; i < n - 1; i++)
        x[i] = x[i+1];
    return x;
}

int* sort(int x[],int n)
{
    int temp_value,min;
    for(int i=0;i<n-1;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if(x[min]>x[j])
                min=j;
        }
        if(min!=i)
        {
            temp_value=x[i];
            x[i]=x[min];
            x[min]=temp_value;
        }
    }
    return x;
}
int search(const int x[],int n,int element_search)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if (x[i] == element_search)
        {
            return i;
        }
    }
    return -1;
}
void merge(int x[], int n, const int array_merge[], int m, int merged[])
{
    int i, j, k;
    j = k = 0;
    for(i=n;i<n+m;i++)
    {
        if(j<m)
        {
            x[i]=array_merge[j];
            j++;
        }
    }
    for(i=0;i<n+m;i++)
    {
        merged[i]=x[i];
    }
}
int* copy(const int x[],int n)
{
    static int copy_arr[100];
    for(int i=0;i<n;i++)
    {
        copy_arr[i]=x[i];
    }
    return copy_arr;
}
int resize(int size,int x[],int n)
{
    n=size;
    return n;
}
int isfull(int n,int max_len)
{
    if(n==max_len)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
int isempty(int n)
{
    if(n==0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
void length(int n)
{
    printf("%i",n);
}

int main(void)
{
    int x[max_len],cases,n,ans=0;
    printf("Enter the size of the array: ");
    scanf("%i",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%i",&x[i]);
    }
    while(ans==0)
    {
        printf("\nThese operation can be performed on the above array: \n1. Traverse the array\n2. Inset an element\n3. Delete an element\n4. Sort the array\n5. Search an element\n6. Merge the array\n7. Copy the array\n8. Resize \n9. Check if the array is full\n10. Check if the array is empty\n11. Length\nChoose the operation you want to perform: ");
        scanf("%i",&cases);
        if(cases==1)//case to traverse the array
        {
            tranverse(x,n);
        }
        if(cases==2)//case to add an element to the array
        {
            int element_add,element_pos;
            printf("Enter element to add in list: ");
            scanf("%d",&element_add);
            printf("Enter position of element: ");
            scanf("%d",&element_pos);
            n++;
            if(n>=element_pos)
            {
                int* ptr_insert=insert_element(x,n,element_add, element_pos);
                for(int i=0;i<n;i++)
                {
                    printf("%d\n", ptr_insert[i]);
                }
            }
            else
            {
                printf("Invalid position");
            }
        }
        if(cases==3)//case to delete an element from the array
        {
            int delete_element_pos;
            printf("Enter the location where you wish to delete element:");
            scanf("%d", &delete_element_pos);
            if (delete_element_pos >= n+1)
                printf("Deletion not possible.\n");
            else
            {
                int* ptr_delete = delete_element(x,n,delete_element_pos);
                n--;
                for(int i=0;i<n;i++)
                {
                    printf("%d\n", ptr_delete[i]);
                }
            }
        }
        if(cases==4)//case to sort the array
        {
            int* ptr_sort = sort(x,n);
            for(int i=0;i<n;i++)
            {
                printf("%d\n", ptr_sort[i]);
            }
        }
        if(cases==5)//case to search an element
        {
            int element_search;
            printf("Enter value to find: ");
            scanf("%d", &element_search);
            int ptr_search = search(x,n,element_search);
            if(ptr_search>=0)
            {
                printf("Element is present at index %d",ptr_search+1);
            }
            if(ptr_search == -1)
            {
                printf("Element is not present in array");
            }
        }
        if(cases==6)// case to merge two diffenret array
        {
            int array_merge[max_len],merged[max_len],m;
            printf("Enter the size of the array you want to merge: ");
            scanf(" %d",&m);
            for(int i=0;i<m;i++)
            {
                printf("Enter the element: ");
                scanf("%d",&array_merge[i]);
            }
            merge(x,n,array_merge,m,merged);
            for (int c = 0; c < n + m; c++)
            {
                printf("%d\n", merged[c]);
            }
        }
        if(cases==7)// case to copy the arrry
        {
            int* ptr_copied=copy(x,n);
            for(int i=0;i<n;i++)
            {
                printf("%d\n", ptr_copied[i]);
            }
        }
        if(cases == 8)//case to resize the array
        {
            int size;
            printf("Enter new size of the array:");
            scanf("%i",&size);
            int ptr_resize=resize(size,x,n);
            n=ptr_resize;
            printf(" new size= %i",n);
        }
        if(cases==9)//case to check if the array is full
        {
            int ptr_full = isfull(n,max_len);
            if(ptr_full==0)
            {
                printf("Given array is full");
            }
            else
            {
                printf("Given array is not full");
            }
        }
        if(cases==10)//case to check of the array is empty
        {
            int ptr_empty = isempty(n);
            if(ptr_empty==0)
            {
                printf("Given array is empty");
            }
            else
            {
                printf("Given array is not empty");
            }
        }
        if(cases==11)//case to print the length of the array
        {
            length(n);
        }
        printf("\nDo you want to perform another operation?\n0 - Yes\n1 - NO\nEnter your choice: ");
        scanf("%d",&ans);
    }
}
