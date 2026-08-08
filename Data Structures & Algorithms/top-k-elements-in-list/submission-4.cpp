class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<int> ans;

        vector<vector<int>> bucket(nums.size() + 1);

        unordered_map<int, int> freq;

        // 1. Count frequency
        for (auto x : nums) {
            freq[x]++;
        }

        // 2. Put elements into bucket according to frequency
        for (auto x : freq) {
            bucket[x.second].push_back(x.first);
        }

        // 3. Traverse buckets from highest frequency
        int count = 0;

        for (int i = bucket.size() - 1;
             count < k && i > 0;
             i--) {

            int j = 0;

            while (count < k && j < bucket[i].size()) {
                ans.push_back(bucket[i][j]);
                j++;
                count++;
            }
        }

        return ans;
    }
};