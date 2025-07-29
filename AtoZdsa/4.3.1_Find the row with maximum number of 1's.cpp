#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lowerBound(const vector<int>& row, int x) {
        int low = 0, high = row.size() - 1;
        int ans = row.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (row[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int rowWithMax1s(vector<vector<int>> &mat) {
        int n = mat.size();
        if (n == 0) return -1;

        int m = mat[0].size();
        int maxCount = 0;
        int index = -1;

        for (int i = 0; i < n; i++) {
            int cntOnes = m - lowerBound(mat[i], 1);
            if (cntOnes > maxCount) {
                maxCount = cntOnes;
                index = i;
            }
        }
        return index;
    }
};