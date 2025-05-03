#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>> ans;
        sort(a.begin(), a.end()); // Sort the array

        for (int i = 0; i < a.size() - 2; i++) {
            // Skip duplicates for the first pointer
            if (i > 0 && a[i] == a[i - 1]) continue;

            int j = i + 1, k = a.size() - 1;

            while (j < k) {
                int sum = a[i] + a[j] + a[k];

                if (sum < 0) {
                    j++; // Move left pointer forward
                } else if (sum > 0) {
                    k--; // Move right pointer backward
                } else {
                    // Found a triplet
                    ans.push_back({a[i], a[j], a[k]});
                    j++;
                    k--;

                    // Skip duplicates for the second pointer
                    while (j < k && a[j] == a[j - 1]) j++;
                    // Skip duplicates for the third pointer
                    while (j < k && a[k] == a[k + 1]) k--;
                }
            }
        }

        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
 set<vector<int>> st;
int n=arr.size();
    for (int i = 0; i < n; i++) {
        set<int> hashset;
        for (int j = i + 1; j < n; j++) {
            //Calculate the 3rd element:
            int third = -(arr[i] + arr[j]);

            //Find the element in the set:
            if (hashset.find(third) != hashset.end()) {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    //store the set in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
     }
};