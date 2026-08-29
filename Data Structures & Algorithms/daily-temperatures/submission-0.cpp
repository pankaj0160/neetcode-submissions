class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        stack<pair<int, int>> stk;  // pair{temp, index}

        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            int t = temperatures[i];

            while (!stk.empty() && t > stk.top().first) {
                pair temp = stk.top();
                stk.pop();
                ans[temp.second] = i - temp.second;
            }
            stk.push({t, i});
        }
        return ans;
    }
};
