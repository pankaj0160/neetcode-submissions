class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int x : nums) {
            mp[x]++;
        }

        vector<pair<int, int>> v;

        for (auto x : mp) {
            v.push_back(x);
        }

        sort(v.begin(), v.end(),
             [](pair<int, int>& p, pair<int, int>& q) { return p.second > q.second; });

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].first);
        }
        return ans;
    }
};
