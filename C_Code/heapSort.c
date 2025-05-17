#include <stdio.h>

// Heapify Function to Maintain Heap Property
void heapify(int arr[], int size, int root) {
    int largest = root;          // Assume root is the largest
    int left = 2 * root + 1;     // Left child
    int right = 2 * root + 2;    // Right child
    
    // Check if left child is larger than root
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    
    // Check if right child is larger than the current largest
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }
    
    // If root is not the largest, swap and heapify the affected sub-tree
    if (largest != root) {
        int temp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = temp;
        
        // Recursively heapify the affected sub-tree
        heapify(arr, size, largest);
    }
}

// Heap Sort Function
void heapSort(int arr[], int size) {
    // Build the max heap (rearrange array)
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
    
    // Extract elements from the heap one by one
    for (int i = size - 1; i >= 0; i--) {
        // Move current root (max) to the end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        
        // Heapify the reduced heap
        heapify(arr, i, 0);
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
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Unsorted Array: ");
    printArray(arr, size);
    
    heapSort(arr, size);
    
    printf("Sorted Array: ");
    printArray(arr, size);
    
    return 0;
}
