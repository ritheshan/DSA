#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int trap(vector<int>& height) {
            vector<int> prefixmax(height.size()), suffixmax(height.size());
            prefixmax[0] = height[0];
            for (int i = 1; i < prefixmax.size(); i++) {
                if (prefixmax[i - 1] >= height[i])
                    prefixmax[i] = prefixmax[i - 1];
                else
                    prefixmax[i] = height[i];
            }
            suffixmax[height.size() - 1] = height[height.size() - 1];
            for (int i = suffixmax.size() - 2; i >= 0; i--) {
                if (suffixmax[i + 1] >= height[i])
                    suffixmax[i] = suffixmax[i + 1];
                else
                    suffixmax[i] = height[i];
            }
            int total = 0;
            for (int i = 0; i < height.size(); i++) {
                int leftmax = prefixmax[i], rightmax = suffixmax[i];
                total += min(leftmax, rightmax) - height[i];
            }
            return total;
        }
    };