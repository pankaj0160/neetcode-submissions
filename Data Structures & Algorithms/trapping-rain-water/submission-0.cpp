class Solution {
   public:
    int trap(vector<int>& height) {
        int i = 0, j = height.size() - 1;

        int left = height[i], right = height[j], res = 0;

        while(i < j){

            if(left < right) {
                i++;
                left = max(left, height[i]);
                res += (left - height[i]);
            }
            else {
                right = max(right, height[j]);
                res += (right - height[j]);
                j--;
            }
        }
        
        return res;
    }
};
