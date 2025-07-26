#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int>& nums, int x) {
        int n = nums.size();
        int low = 0, high = n;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] < x)
                low = mid + 1;
            else
                high = mid;
        }

        return low;  // First index where nums[i] >= x
    }
};