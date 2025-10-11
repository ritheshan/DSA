#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
void reverseRange(string &s, int l, int r) {
    while (l < r) swap(s[l++], s[r--]);
}

string reverseWords(string s) {
    int n = s.size();
    
    // Step 1: Reverse the entire string
    reverseRange(s, 0, n - 1);
    
    int write = 0;  // where to write cleaned chars
    int i = 0;      // read pointer

    while (i < n) {
        // Skip spaces
        while (i < n && s[i] == ' ') i++;
        if (i >= n) break;

        // Start of a word
        int j = i;
        while (j < n && s[j] != ' ') j++;

        // Step 2: Reverse this word back to correct order
        reverseRange(s, i, j - 1);

        // Step 3: Compact the word to front of string
        if (write > 0) s[write++] = ' '; // add single space
        for (int k = i; k < j; k++)
            s[write++] = s[k];

        i = j;
    }

    s.resize(write); // remove trailing garbage
    return s;
}

};