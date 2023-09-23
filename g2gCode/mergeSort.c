// C program for Merge Sort
#include <stdio.h>
#include <stdlib.h>

int steps = 0;

// Function to print an array
void printArray(int A[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    printf("\tL = {");
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
        printf("%d, ", L[i]);
    }
    printf("}\n");
    printf("\tR = {");
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
        printf("%d, ", R[j]);
    }
    printf("}\n");
    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    printf("\tSteps %2d: ", steps);
    for (int i = 0; i < 8; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    steps += 1;
}

// l is for left index and r is right index of the
// sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r) {
    if (l < r) {  // return
        int m = l + (r - l) / 2;
        printf("Mid = %d\n", m);
        // Sort first and second halves
        printf("Split left (%d, %d)\n", l, m);
        mergeSort(arr, l, m);
        printf("End split left (%d, %d)\n\n", l, m);
        printf("Split right (%d, %d)\n", m + 1, r);
        mergeSort(arr, m + 1, r);
        printf("End split right (%d, %d)\n\n", m + 1, r);

        merge(arr, l, m, r);
        printf("Merge done (%d, %d, %d)\n", l, m, r);
    }
}

// Driver code
int main() {
    // int arr[] = {64, 34, 25, 12, 22, 11, 90, 1, 4, 6, 8, 12, 91, 31, 5, 1, 6, 9, 10, 11, 12, 1};
    int arr[] = {64, 34, 25, 12, 22, 11, 90};

    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
