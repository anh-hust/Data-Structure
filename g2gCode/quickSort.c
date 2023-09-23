// C code to implement quicksort

#include <stdio.h>

int steps = 0;

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition the array using the last element as the pivot
int partition(int arr[], int low, int high) {
    // Choosing the pivot
    int pivot = arr[high];

    // Index of smaller element and indicates
    // the right position of pivot found so far
    int i = (low - 1);
    printf("\n\t%d ", i);

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            // Increment index of smaller element
            i++;
            swap(&arr[i], &arr[j]);
            printf("\n\tStep %d (pivot = %d): ", steps, pivot);
            for (int i = low; i < high; i++) {
                printf("%d ", arr[i]);
            }
        }
    }
    swap(&arr[i + 1], &arr[high]);

    printf("\n\tArray: ");
    for (int i = 0; i < 22; i++) {
        printf(" %d, ", arr[i]);
    }
    printf("\n");
    steps += 1;
    return (i + 1);
}

// The main function that implements QuickSort
// arr[] --> Array to be sorted,
// low --> Starting index,
// high --> Ending index
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[p]
        // is now at right place
        int pi = partition(arr, low, high);
        printf("\nEnd of partition, position = %d, pivot = %d", pi, arr[pi]);

        // Separately sort elements before
        // partition and after partition
        printf("\nStart lower partition (low = %d, high = %d)", low, pi - 1);
        quickSort(arr, low, pi - 1);
        printf("\nEnd lower partition (low = %d, high = %d)", low, pi - 1);
        printf("\nStart greater partition (low = %d, high = %d)", pi + 1, high);
        quickSort(arr, pi + 1, high);
        printf("\nEnd greater partition (low = %d, high = %d)", pi + 1, high);
    }
}

// Driver code
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 1, 4, 6, 8, 12, 91, 31, 5, 1, 6, 9, 10, 11, 12, 1};
    int N = sizeof(arr) / sizeof(arr[0]);

    // Function call
    printf("Input array: \n");
    for (int i = 0; i < N; i++)
        printf("%d, ", arr[i]);

    quickSort(arr, 0, N - 1);
    printf("\nSorted array: \n");
    for (int i = 0; i < N; i++)
        printf("%d, ", arr[i]);
    return 0;
}
