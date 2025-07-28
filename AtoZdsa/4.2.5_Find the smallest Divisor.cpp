#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int finddiv(vector<int>& nums, int div) {
        int sum = 0;
        for (int num : nums) {
            sum += (num + div - 1) / div; // same as ceil(num / div)
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int curr_sum = finddiv(nums, mid);

            if (curr_sum <= threshold) {
                ans = mid;         // try smaller divisor
                high = mid - 1;
            } else {
                low = mid + 1;     // need larger divisor
            }
        }

        return ans;
    }
};