class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int prev = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < prev)
                prev = prices[i];
            else
                ans = max(ans, (prices[i] - prev));
        }
        return ans;
    }
};
