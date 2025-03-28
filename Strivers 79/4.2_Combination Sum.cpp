#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void findcombination(int ind, vector<int>& arr, int target,
                             vector<vector<int>>& ans, vector<int>& ds) {
            if (target == 0) {
                ans.push_back(ds);
                return;
            }
            if (ind == arr.size()) {
                return;
            }
            // Take the element if it's less than or equal to the target
            if (arr[ind] <= target) {
                ds.push_back(arr[ind]);
                findcombination(ind, arr, target - arr[ind], ans, ds);
                ds.pop_back();
            }
            // Do not take the element and move to the next index
            findcombination(ind + 1, arr, target, ans, ds);
        }
    
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> ans;
            vector<int> ds;
            findcombination(0, candidates, target, ans, ds);
            return ans;
        }
    };