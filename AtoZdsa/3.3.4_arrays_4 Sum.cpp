
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        vector<vector<int>> ans;
        if (a.size() < 4)
            return ans;
        sort(a.begin(), a.end()); // Sort the array

        for (int i = 0; i < a.size() - 3; i++) {
            if (i > 0 && a[i] == a[i - 1])
                continue; // Skip duplicate `i`
            for (int j = i + 1; j < a.size() - 2; j++) {
                if (j > i + 1 && a[j] == a[j - 1])
                    continue; // Skip duplicate `j`
                int k = j + 1, l = a.size() - 1;
                while (k < l) {
                    long sum = (long)a[i] + a[j] + a[k] + a[l];
                    if (sum < target) {
                        k++;
                    } else if (sum > target) {
                        l--;
                    } else {
                        ans.push_back({a[i], a[j], a[k], a[l]});
                        k++;
                        l--;
                        // Skip duplicate `k`
                        while (k < l && a[k] == a[k - 1])
                            k++;
                        // Skip duplicate `l`
                        while (k < l && a[l] == a[l + 1])
                            l--;
                    }
                }
            }
        }

        return ans;
    }
};

// using set and 
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    set<vector<int>> st;

    //checking all possible quadruplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            set<long long> hashset;
            for (int k = j + 1; k < n; k++) {
                // taking bigger data type
                // to avoid integer overflow:
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long fourth = target - sum;
                if (hashset.find(fourth) != hashset.end()) {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)(fourth)};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                // put the kth element into the hashset:
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}