#include <unordered_set>
#include <string>
using namespace std;


// brutefore

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;

        // Iterate through each starting index `j`
        for (int j = 0; j < s.size(); j++) {
            unordered_set<char> Set; // Reset set for the new starting point
            int currentLength = 0;

            // Iterate through the substring starting at `j`
            for (int i = j; i < s.size(); i++) {
                if (Set.find(s[i]) == Set.end()) {
                    Set.insert(s[i]);
                    currentLength++;
                } else {
                    break; // Stop when a duplicate is found
                }
            }

            // Update the maximum length
            maxLength = max(maxLength, currentLength);
        }

        return maxLength;
    }
};
