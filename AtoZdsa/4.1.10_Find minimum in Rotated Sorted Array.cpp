#include <vector>
#include <climits>
#include <algorithm> // For std::min

class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int minValue = nums[0]; // Initialize with the first element

        // If the array is already sorted, return the first element
        if (nums[left] <= nums[right]) {
            return nums[left];
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;
            minValue = std::min(minValue, nums[mid]); // Update the minimum value

            // If the left part is sorted, move to the right
            if (nums[left] <= nums[mid]) {
                minValue = std::min(minValue, nums[left]); // Take the first element of the sorted left part
                left = mid + 1;
            } else { 
                // Otherwise, the right part is unsorted, move left
                minValue = std::min(minValue, nums[mid + 1]); // Take the first element of the right part
                right = mid - 1;
            }
        }
        
        return minValue;
    }
};