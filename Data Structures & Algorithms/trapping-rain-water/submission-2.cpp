class Solution {
   public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        int i = 0, j = height.size() - 1;

        int left = height[i], right = height[j], res = 0;

        while (i < j) {
            left = max(left, height[i]);
            right = max(right, height[j]);

            if (left < right) {
                res += (left - height[i]);
                i++;
            } else {
                res += (right - height[j]);
                j--;
            }
        }

        return res;
    }
};
