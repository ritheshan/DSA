#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        stack<int> st;

        // Populate the map with next greater elements in nums2
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if (st.empty()) {
                map[nums2[i]] = -1;
            } else {
                map[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }

        // Replace elements in nums1 with their next greater element from nums2
        for (int i = 0; i < nums1.size(); i++) {
            nums1[i] = map[nums1[i]];
        }

        return nums1;
    }
};