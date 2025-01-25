#include <iostream>
#include <vector>
using namespace std;

// Merge function to count inversions
int mergeAndCount(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    vector<int> leftArr(n1), rightArr(n2);
    for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++) rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left, swaps = 0;

    // Merge the two halves and count inversions
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
            swaps += (n1 - i);  // Count inversions
        }
    }

    // Copy remaining elements
    while (i < n1) arr[k++] = leftArr[i++];
    while (j < n2) arr[k++] = rightArr[j++];

    return swaps;
}

// Merge Sort function to count inversions
int mergeSortAndCount(vector<int> &arr, int left, int right) {
    int invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        invCount += mergeSortAndCount(arr, left, mid);
        invCount += mergeSortAndCount(arr, mid + 1, right);

        invCount += mergeAndCount(arr, left, mid, right);
    }
    return invCount;
}

// Function to count inversions in an array
int inversionCount(vector<int> &arr) {
    return mergeSortAndCount(arr, 0, arr.size() - 1);
}