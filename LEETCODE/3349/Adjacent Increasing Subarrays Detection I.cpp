#include<bits/stdc++.h>
using namespace std;

// Brute force O(n*k) time and O(n) space
class Solution {
public:
    bool is_increasing(vector<int>& nums, int k, int start) {
        for (int i = start; i < start + k - 1; i++) {
            if (nums[i] >= nums[i + 1])
                return false;
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        vector<int> isinc(nums.size(), 0);
        for (int i = 0; i + k <= nums.size(); i++) {
            if (is_increasing(nums, k, i)) {
                isinc[i] = 1;
            }
        }
        for (int i = 0; i + k < nums.size(); i++) {
            if (isinc[i] && isinc[i + k]) {
                return true;
            }
        }
        return false;
    }
};

// Optimized version O(n) time and O(1) space
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int len = 1;  // current increasing streak length
        int last_end = -1;  // last subarray end index of length k

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) len++;
            else len = 1;

            if (len >= k) {
                if (last_end != -1 && i - last_end == k)
                    return true;
                last_end = i;
            }
        }
        return false;
    }
};