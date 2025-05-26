#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int binarysearch(vector<int>& nums, int low, int high, int target) {
        if (low > high) return -1;
        
        int mid = low + (high - low) / 2;  // Prevent overflow
        
        if (nums[mid] == target) return mid;
        if (nums[mid] > target) return binarysearch(nums, low, mid - 1, target);
        return binarysearch(nums, mid + 1, high, target);
    }

    int search(vector<int>& nums, int target) {
        return binarysearch(nums, 0, nums.size() - 1, target);
    }
};
