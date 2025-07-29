#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool possible(vector<int>& bloom, int day, int m, int k) {
        int cnt = 0, ans = 0;
        for (int i : bloom) {
            if (i <= day) {
                cnt++;
            } else {
                ans += cnt / k;
                cnt = 0;
            }
        }
        ans += cnt / k;
        if (ans >= m)
            return true;
        else
            return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        long long val = m * 1ll * k * 1ll;
        int n = bloomDay.size(); // size of the array
        if (val > n)
            return -1; // impossible case.

        int min = *min_element(bloomDay.begin(), bloomDay.end());
        int max = *max_element(bloomDay.begin(), bloomDay.end());
        while (min <= max) {
            int mid = min + (max - min) / 2;
            if (possible(bloomDay, mid, m, k)) {
                max = mid - 1;
            } else {
                min = mid + 1;
            }
        }
        return min;
    }
};