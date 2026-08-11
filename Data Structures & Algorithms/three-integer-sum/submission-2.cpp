class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // using hanshmap

        sort(nums.begin(), nums.end());
        unordered_map<int, int> count;
        for (int x : nums) {
            count[x]++;
        }

        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++) {
            int first = nums[i];
            count[first]--;
            // skip duplicates
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < nums.size(); j++) {
                count[nums[j]]--;
                // skip duplicate
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int target = -(nums[i] + nums[j]);
                if (count[target] > 0) ans.push_back({first, nums[j], target});
            }
            for (int j = i + 1; j < nums.size(); j++) {
                count[nums[j]]++;
            }
        }
        return ans;
    }
};
