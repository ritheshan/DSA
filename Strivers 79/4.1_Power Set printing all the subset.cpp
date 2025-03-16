// using bit manipulation to generate all the subsets of a set

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<int> ans;
            vector<vector<int>> temp;
            for (int k = 0; k < 1 << nums.size(); k++) {
                vector<int> ans = {};
                for (int i = 0; i < nums.size(); i++) {
                    if (k & (1 << i)) {
                        ans.push_back(nums[i]);
                    }
                }
                temp.push_back(ans);
            }
    
            return temp;
        }
    };


// using backtracking (recursion) to generate all the subsets of a set

class Solution {
    public:
        vector<vector<int>> result; // Stores all subsets
    
        void generateSubsets(vector<int>& nums, int index, vector<int>& temp) {
            if (index == nums.size()) {
                result.push_back(temp);
                return;
            }
    
            // Exclude current element
            generateSubsets(nums, index + 1, temp);
    
            // Include current element
            temp.push_back(nums[index]);
            generateSubsets(nums, index + 1, temp);
            temp.pop_back(); // Backtrack
        }
    
        vector<vector<int>> subsets(vector<int>& nums) {
            result.clear(); // Ensure no leftover data
            vector<int> temp;
            generateSubsets(nums, 0, temp);
            return result;
        }
    };