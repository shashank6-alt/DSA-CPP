#include <stdio.h>

// Merge two subarrays
void merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;
    int temp[100];

    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= mid)
        temp[k++] = arr[i++];

    while(j <= high)
        temp[k++] = arr[j++];

    for(i = low, k = 0; i <= high; i++, k++)
        arr[i] = temp[k];
}

// Merge Sort function
void mergeSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

// Main function
int main()
{
    int n, i;
    int arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array using Merge Sort:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
