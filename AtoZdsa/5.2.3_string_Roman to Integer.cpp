#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanmap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int total = 0;
        int n = s.size();

        for (int i = 0; i < n - 1; i++) {
            if (romanmap[s[i]] < romanmap[s[i + 1]])  
                total -= romanmap[s[i]];
            else
                total += romanmap[s[i]];
        }

        total += romanmap[s[n - 1]]; 
        return total;
    }
};