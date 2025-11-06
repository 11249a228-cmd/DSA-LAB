#include <stdio.h>
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2; // To avoid overflow
        if(arr[mid] == target)
            return mid; // Found the target
        else if(arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Not found
}
int main() {
    int arr[] = {2, 3, 5, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 6;
    int result = binarySearch(arr, n, target);
    if(result != -1)
        printf("Element %d found at index %d", target, result);
    else
        printf("Element %d not found", target);
    return 0;
}
