#include <algorithm> // For std::sort
#include <climits>   // For INT_MAX
#include <cmath>     // For std::ceil>
#include <numeric>   // For std::accumulate
#include <vector>

class Solution {
public:
    int total(std::vector<int>& piles, int k) {
        int totalhours = 0;
        for (int x : piles) {
            totalhours += std::ceil(double(x) / k);
        }
        return totalhours;
    }

    int minEatingSpeed(std::vector<int>& piles, int h) {
        int low = 1;
        int high = *std::max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = (low + high) / 2;
            int totalhours = total(piles, mid);

            if (totalhours <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};