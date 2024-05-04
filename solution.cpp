#include "util.cpp"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; // store the index in heights

        int len = heights.size();
        int ans = 0;
        for (int i = 0; i < len; ++i) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int cur_index = st.top();
                st.pop();
                int cur_area = heights[cur_index] * (i - (st.empty() ? -1 : st.top()) -1);
                ans = max(ans, cur_area);
            }
            st.push(i);
        }

        while (!st.empty()) {
            int cur_index = st.top();
            st.pop();
            int cur_area = heights[cur_index] * (len - (st.empty() ? -1 : st.top()) - 1);
            ans = max(ans, cur_area);
        }

        return ans;
    }
};