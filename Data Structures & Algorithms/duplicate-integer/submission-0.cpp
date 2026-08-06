class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        // 1st method i would like to try is sorting

        sort(nums.begin(), nums.end());

        int prev = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == prev) return true;
            prev = nums[i];
        }
        return false;
    }
};