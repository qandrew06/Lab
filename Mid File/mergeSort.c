#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int t[], int lb, int mid, int ub)
{
    int i = lb, j = mid + 1, k = lb;
    while (i <= mid && j <= ub)
    {
        if (arr[i] < arr[j])
            t[k++] = arr[i++];
        else
            t[k++] = arr[j++];
    } 

    // Copy remaining left elements
    while (i <= mid)
        t[k++] = arr[i++];

    // Copy remaining right elements
    while (j <= ub)
        t[k++] = arr[j++];

    // Copy back to original array
    for (i = lb; i <= ub; i++)
        arr[i] = t[i];
}

void mergeSort(int arr[], int t[], int lb, int ub)
{
    int mid = 0;
    if(lb < ub)
    {
        mid = (lb + ub) / 2;
        mergeSort(arr, t, lb, mid);
        mergeSort(arr, t, mid + 1, ub);
        merge(arr, t, lb, mid, ub);
    }
}

int main()
{
    int arr[100], t[100], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, t, 0, n-1);

    printf("Sorted array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}