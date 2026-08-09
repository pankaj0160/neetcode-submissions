class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        int compute = nums[0];
        ans[0] = 1;

        for (int i = 1; i < nums.size(); i++) {
            ans[i] = ans[i - 1] * compute;
            compute = nums[i];
        }

        compute = 1;

        for (int i = nums.size() - 1; i >= 0; i--) {
            ans[i] *= compute;
            compute *= nums[i];
        }
        return ans;
    }
};
