#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helper(string& s, int i, long long result, bool is_negative) {
        if (i == s.length() || !isdigit(s[i]))
            return is_negative ? -result : result;

        int digit = s[i] - '0';

        if (!is_negative && result > (INT_MAX - digit) / 10)
            return INT_MAX;

        if (is_negative && result > ((long long)INT_MAX + 1 - digit) / 10)
            return INT_MIN;

        long long new_result = result * 10 + digit;

        return helper(s, i + 1, new_result, is_negative);
    }

    int myAtoi(string s) {
        int n = s.size();
        int i = 0;

        // Skip leading whitespace
        while (i < n && isspace(s[i])) i++;

        // Check for sign
        bool is_negative = false;
        if (i < n && s[i] == '-') {
            is_negative = true;
            i++;
        } else if (i < n && s[i] == '+') {
            i++;
        }

        return helper(s, i, 0LL, is_negative);
    }
};