class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            stack<int> st;  // Monotonic increasing stack
            int maxA = 0;
            int n = heights.size();
            
            for (int nse = 0; nse <= n; nse++) {  // nse = Next Smaller Element
                while (!st.empty() && (nse == n || heights[st.top()] >= heights[nse])) {
                    int height = heights[st.top()];  // Current element being processed
                    st.pop();
                    
                    int pse; // Previous Smaller Element
                    if (st.empty())
                        pse = -1;  // No PSE, means full width from start
                    else
                        pse = st.top();  // Top of stack is the Previous Smaller Element
                    
                    int width = nse - pse - 1;  // Width between NSE and PSE
                    maxA = max(maxA, width * height);
                }
                st.push(nse);  // Push NSE as a potential PSE for upcoming elements
            }
            
            return maxA;
        }
    };