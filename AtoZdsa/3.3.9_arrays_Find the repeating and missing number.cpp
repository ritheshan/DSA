#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
         int n = arr.size();
        long long sum = 0; // Sum of elements in the array
        long long expected_sum = (long long) n * (n + 1) / 2; // Sum of first n natural numbers
        unordered_set<int> seen;
        int repeating = -1;
        
        // Traverse the array to find the repeating number and compute the sum
        for (int num : arr) {
            sum += num;
            if (seen.find(num) != seen.end()) {
                repeating = num; // Found the repeating number
            } else {
                seen.insert(num);
            }
        }
        
        // The missing number is the difference between the expected sum and the actual sum,
        // adjusted by the repeating number.
        long missing = expected_sum - (sum - repeating);
        
        return { repeating,missing};
    }
    
};