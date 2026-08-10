class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;

        for (auto num : s) {
            // if it is starting of sequence
            if (s.find(num - 1) == s.end()) {
                int len = 0;
                while (s.find(num + len) != s.end()) len++;
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
