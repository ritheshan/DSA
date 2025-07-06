#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countOccurrences(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        if (first == -1) return 0; // target not found
        int last = findLast(nums, target);
        return last - first + 1;
    }

private:
    int findFirst(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                result = mid;
                high = mid - 1; // go left
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }

    int findLast(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                result = mid;
                low = mid + 1; // go right
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }
};