// Optimized implementation of Bubble sort
#include <stdbool.h>
#include <stdio.h>

void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j;
    int steps = 0;
    bool swapped;
    // because after first sort (i=0, the largest element already in the last position)
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
            printf("Step %3d (i = %d, j = %d): ", steps, i, j);
            printArray(arr, n);

            steps += 1;
        }

        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
            break;
    }
}

// Driver program to test above functions
int main() {
    printf("===== Bubble sort =====");
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 1, 4, 6, 8, 12, 91, 31, 5, 1, 6, 9, 10, 11, 12, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}