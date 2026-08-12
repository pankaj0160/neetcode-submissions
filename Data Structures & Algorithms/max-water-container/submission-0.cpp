class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;
        int maxwater = 0;
        int ans = 0;

        while (i < j) {
            int h = min(heights[i], heights[j]);
            int w = j - i;

            maxwater = h * w;
            ans = max(ans, maxwater);

            if (heights[i] > heights[j])
                j--;
            else
                i++;
        }
        return ans;
    }
};
