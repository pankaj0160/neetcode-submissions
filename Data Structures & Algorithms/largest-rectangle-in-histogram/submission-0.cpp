class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;

        int maxarea = 0;

        for (int i = 0; i <= heights.size(); i++) {
            
            int currentH = (i == heights.size()) ? 0 : heights[i];

            while (!st.empty() && currentH < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();

                int width = (st.empty()) ? i : i - 1 - st.top();

                maxarea = max(maxarea, h * width);
            }
            st.push(i);
        }
        return maxarea;
    }
};
