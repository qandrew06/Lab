#include <stdio.h> 
int binarySearch(int arr[], int n, int key) { 
    int low = 0, high = n - 1; 
    while (low <= high) { 
        int mid = low + (high - low) / 2; 
        if (arr[mid] == key) 
            return mid; 
        else if (arr[mid] < key) 
            low = mid + 1; 
        else 
            high = mid - 1; 
    } 
    return -1; 
} 
 
int main() { 
    int n, key; 
    printf("Enter number of elements: "); 
    scanf("%d", &n); 
 
    int arr[n]; 
    printf("Enter %d sorted elements:\n", n); 
    for (int i = 0; i < n; i++) { 
        scanf("%d", &arr[i]); 
    } 
 
    printf("Enter element to search: "); 
    scanf("%d", &key); 
 
    int result = binarySearch(arr, n, key); 
 
    if (result != -1) 
        printf("Element %d found at position %d\n", key, result + 1); 
    else 
        printf("Element %d not found in the array.\n", key); 
 
    return 0; 
}