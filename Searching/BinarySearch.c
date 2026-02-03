#include <stdio.h>

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int n, int target) {
        int left = 0, right = n - 1;
        while (left <= right) {
                int mid = left + (right - left) / 2;
                if (arr[mid] == target)
                        return mid; // Target found at index mid
                else if (arr[mid] < target)
                        left = mid + 1; // Search right half
                else
                        right = mid - 1; // Search left half
        }
        return -1; // Target not found
}

int main() {
        int arr[] = {2, 4, 7, 10, 23, 38, 56, 72, 91};
        int n = sizeof(arr) / sizeof(arr[0]);
        int target = 23;

        int result = binarySearch(arr, n, target);
        if (result != -1)
                printf("Element %d found at index %d\n", target, result);
        else
                printf("Element %d not found in the array\n", target);

        return 0;
}