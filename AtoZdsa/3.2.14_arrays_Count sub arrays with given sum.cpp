#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   int subarraySum(vector<int>& arr, int k) {
    map<int, int> map;
    int sum = 0;
    int count = 0;

    // Traverse the array
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        // If sum equals k, increment count
        if (sum == k) {
            count++;
        }

        // Check if `sum - k` exists in the map
        int rem = sum - k;
        if (map.find(rem) != map.end()) {
            count += map[rem]; // Add all occurrences of `rem`
        }

        // Update the frequency of the current sum
        map[sum]++;
    }

    return count;
}

};