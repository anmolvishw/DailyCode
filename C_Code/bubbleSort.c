#include <stdio.h>

// Bubble Sort Function
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        // If no two elements were swapped, the array is sorted
        if (swapped == 0) {
            break;
        }
    }
}

// Print Array Function
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {17,15,10,7,0,1,-5,11,2,16};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Unsorted Array: ");
    printArray(arr, size);
    
    bubbleSort(arr, size);
    
    printf("Sorted Array: ");
    printArray(arr, size);
    
    return 0;
}
