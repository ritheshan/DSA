class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return {first, last};
    }

private:
    int findFirst(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                result = mid;
                high = mid - 1;
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
                low = mid + 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }
};
// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int low = 0, high = nums.size() - 1;
//         int first = -1, last = -1;

//         while (low <= high) {
//             int mid = low + (high - low) / 2;

//             if (nums[mid] < target) {
//                 low = mid + 1;
//             } else if (nums[mid] > target) {
//                 high = mid - 1;
//             } else {
//                 // target found
//                 first = last = mid;

//                 // Expand outward from mid to find boundaries
//                 int l = mid, r = mid;
//                 while (l - 1 >= 0 && nums[l - 1] == target) l--;
//                 while (r + 1 < nums.size() && nums[r + 1] == target) r++;

//                 return {l, r}; // early return
//             }
//         }

//         return {-1, -1};
//     }
// };