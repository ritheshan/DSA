#include <bits/stdc++.h>   
using namespace std;
class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            int left = 0, right = nums.size() - 1;
            while (left <= right) {  // Fix: Use <= to ensure last element is checked
                int mid = (left + right) / 2;
                if (nums[mid] == target) return true;
    
                // Handling duplicates
                if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                    left++;
                    right--;
                    continue;
                }
    
                // Left half is sorted
                if (nums[left] <= nums[mid]) {
                    if (nums[left] <= target && target <= nums[mid]) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                // Right half is sorted
                else {
                    if (nums[mid] <= target && target <= nums[right]) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            }
            return false;
        }
    };