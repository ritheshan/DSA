#include<vector>
using namespace std;
class Solution {
  public:
    // Function to find pair with maximum sum
   
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int>& arr) {
        // Handle edge cases: array with less than 2 elements
        if (arr.size() < 2) {
            return -1; // No pairs exist
        }

        int maxSum = INT_MIN;

        // Iterate through the array to find the maximum sum of adjacent pairs
        for (int i = 0; i < arr.size() - 1; i++) {
            int sum = arr[i] + arr[i + 1];
            if (sum > maxSum) {
                maxSum = sum;
            }
        }

        return maxSum;
    }

};