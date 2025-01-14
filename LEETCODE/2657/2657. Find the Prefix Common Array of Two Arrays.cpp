
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> seen;  // Set to keep track of elements seen so far
        vector<int> ans;
        int commonCount = 0;      // Count of common elements

        for (int i = 0; i < A.size(); i++) {
            // Check for elements from A and B
            if (seen.count(A[i])) {
                commonCount++;    // A[i] is already in the set
            }
            seen.insert(A[i]);    // Add A[i] to the set

            if (seen.count(B[i])) {
                commonCount++;    // B[i] is already in the set
            }
            seen.insert(B[i]);    // Add B[i] to the set

            ans.push_back(commonCount);  // Update the prefix common count
        }

        return ans;
    }
};


class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int> a, b; // Sets to track elements from A and B
        int count = 0; // Count of common elements
        vector<int> ans;

        for (int i = 0; i < A.size(); i++) {
            a.insert(A[i]); // Insert current element of A into set a
            b.insert(B[i]); // Insert current element of B into set b
            count = 0;      // Reset count for this prefix

            // Iterate through set a and check for common elements in b
            for (auto it = a.begin(); it != a.end(); ++it) {
                if (b.find(*it) != b.end()) {
                    count++;
                }
            }

            ans.push_back(count); // Append the count to the result
        }

        return ans;
    }
};


class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> freq;  // To track the frequency of numbers
        vector<int> ans;              // To store the result
        int commonCount = 0;          // Count of common elements

        for (int i = 0; i < A.size(); i++) {
            // Increment frequency for A[i]
            freq[A[i]]++;
            if (freq[A[i]] == 2) { // A[i] is now common between A and B
                commonCount++;
            }

            // Increment frequency for B[i]
            freq[B[i]]++;
            if (freq[B[i]] == 2) { // B[i] is now common between A and B
                commonCount++;
            }

            ans.push_back(commonCount); // Add the current count of common elements
        }

        return ans;
    }
};
