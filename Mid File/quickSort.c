#include <stdio.h>
#include <stdlib.h>

void quickSort(int arr[], int lb, int ub)
{
    int i = lb, j = ub, key = arr[lb], temp = 0;

    if (lb >= ub)
        return;

    while (i < j)
    {
        while (key >= arr[i] && i < j)
            i++;

        while (key < arr[j])
            j--;

        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    arr[lb] = arr[j];
    arr[j] = key;

    quickSort(arr, lb, j - 1);
    quickSort(arr, j + 1, ub);
}

int main()
{
    int arr[100], n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}