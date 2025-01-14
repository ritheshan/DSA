#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//brute force 
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size(); // size of the array

    //sort the given intervals:
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) { // select an interval:
        int start = arr[i][0];
        int end = arr[i][1];

        //Skip all the merged intervals:
        if (!ans.empty() && end <= ans.back()[1]) {
            continue;
        }

        //check the rest of the intervals:
        for (int j = i + 1; j < n; j++) {
            if (arr[j][0] <= end) {
                end = max(end, arr[j][1]);
            }
            else {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}
// optimal solution
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size(); // size of the array

    //sort the given intervals:
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        // if the current interval does not
        // lie in the last interval:
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        // if the current interval
        // lies in the last interval:
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

// overhead brute force
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int i = 0;
        sort(arr.begin(),arr.end()); 
        
        // Repeat until there are no more pairs to merge
        while (i < arr.size() - 1) {
            // Check if second element of the first subarray is greater than the first element of the second subarray
            if (arr[i][1] >= arr[i + 1][0]) {
                // Combine the first and second subarrays
                vector<int> combined;
                combined.insert(combined.end(), arr[i].begin(), arr[i].end());
                combined.insert(combined.end(), arr[i + 1].begin(), arr[i + 1].end());

                // Sort the combined array
                sort(combined.begin(), combined.end());

                // Insert only the first and last element of the sorted combined array
                vector<int> newSubarray = {combined.front(), combined.back()};

                // Erase the merged subarrays
                arr.erase(arr.begin() + i);
                arr.erase(arr.begin() + i); // After the first erase, the next element shifts to the current index

                // Insert the new subarray back into the array
                arr.insert(arr.begin() + i, newSubarray);
            } else {
                // If the condition isn't met, move to the next pair of subarrays
                i++;
            }
        }

        return arr; // Return the final merged array
    }
};