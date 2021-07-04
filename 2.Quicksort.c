#include <stdio.h>
int fc;

void quicksort (int [], int, int);

int main()
{
    int arr[50];
    int size, i;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    for (i = 0; i < size; i++)
    {
        printf("Enter Element No. %d: ",i+1);
        scanf("%d", &arr[i]);
    }
    quicksort(arr, 0, size - 1);
    printf("After applying quick sort: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nThe Time Complexity is: %d \n",fc);
    printf("\n");
    return 0;
}

void quicksort(int arr[], int left, int right)
{
    int pivot, i, j, temp;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    if (left < right)
    {
        pivot = (left + right) / 2;
        i = left;
        j = right;
        while (i < j)
        {
            while (arr[i] <= arr[pivot] && i <= right)
            {
                i++;
                count1++;
            }
            while (arr[j] > arr[pivot] && j >= left)
            {
                j--;
                count2++;
            }
            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                count3++;
            }
            count4++;
        }
        temp = arr[j];
        arr[j] = arr[pivot];
        arr[pivot] = temp;
        quicksort(arr, left, j - 1);
        quicksort(arr, i + 1, right);
    }
    fc = count1 + count2 + count3 + count4;
}
