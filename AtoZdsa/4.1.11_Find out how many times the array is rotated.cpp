#include<bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            if (arr[low] <= arr[high]) {
                return low;  // array is sorted
            }

            int mid = (low + high) / 2;
            int next = (mid + 1) % n;
            int prev = (mid + n - 1) % n;

            if (arr[mid] <= arr[prev] && arr[mid] <= arr[next]) {
                return mid;
            }

            if (arr[mid] >= arr[low]) {
                low = mid + 1;  // left part is sorted, go right
            } else {
                high = mid - 1;  // right part is sorted, go left
            }
        }

        return 0;
    }
};