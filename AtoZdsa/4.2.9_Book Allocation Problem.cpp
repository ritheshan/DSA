#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int countstudent(vector<int> &arr, int m) {
    int cntstd = 1, pages = 0; // Start counting from 1 student
    for (int i = 0; i < arr.size(); i++) {
        if (pages + arr[i] <= m) {
            pages += arr[i];
        } else {
            cntstd++;
            pages = arr[i];
        }
    }
    return cntstd;
}

int findPages(vector<int>& arr, int n, int m) {
    if (m > n) return -1; // Edge case: More students than books

    int maxElement = *max_element(arr.begin(), arr.end()); 
    int sum = accumulate(arr.begin(), arr.end(), 0);
    
    int low = maxElement, high = sum, result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int cntstd = countstudent(arr, mid);

        if (cntstd > m) {
            low = mid + 1;
        } else {
            result = mid; // Store potential answer
            high = mid - 1; // Try to minimize max pages
        }
    }
    return result;
}