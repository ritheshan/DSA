#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void trim(std::string& s) {
        // Remove leading whitespace
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char c) {
            return !std::isspace(c);
        }));

        // Remove trailing whitespace
        s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char c) {
            return !std::isspace(c);
        }).base(), s.end());
    }

    int myAtoi(string s) {
        // Trim whitespace from the string
        trim(s);

        if (s.empty()) return 0;

        // Variables
        bool is_negative = false;
        int number = 0;

        // Process sign if present
        size_t i = 0;
        if (s[i] == '-') {
            is_negative = true;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        // Traverse through the string
        for (; i < s.size(); i++) {
            char x = s[i];
            if (x >= '0' && x <= '9') {
                int digit = x - '0';

                // Check for overflow
                if (number > (INT_MAX - digit) / 10) {
                    return is_negative ? INT_MIN : INT_MAX;
                }

                number = number * 10 + digit;
            } else {
                break; // Stop processing at the first non-digit character
            }
        }

        return is_negative ? -number : number;
    }
};
