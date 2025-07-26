#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getFloorAndCeil(vector<int>& nums, int x) {
        vector<int> ans(2, -1); // ans[0] = floor, ans[1] = ceil
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == x) {
                ans[0] = ans[1] = nums[mid];
                break;
            } else if (nums[mid] < x) {
                ans[0] = nums[mid]; // candidate for floor
                low = mid + 1;
            } else {
                ans[1] = nums[mid]; // candidate for ceil
                high = mid - 1;
            }
        }

        return ans;
    }
};
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size();

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid;
        }

        return low; // First index where nums[i] >= target
    }
};