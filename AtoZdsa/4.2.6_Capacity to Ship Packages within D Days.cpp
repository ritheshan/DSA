#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool possible(vector<int>& weights, int days, int capacity) {
        int sum = 0,
            cnt = 1; // cnt starts at 1 since we begin loading the first day
        for (auto num : weights) {
            if (num > capacity)
                return false; // can't load item heavier than capacity
            if (sum + num > capacity) {
                cnt++;
                sum = num;
            } else {
                sum += num;
            }
        }
        return cnt <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(weights, days, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};