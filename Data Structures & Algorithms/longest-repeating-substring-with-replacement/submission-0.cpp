class Solution {
   public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;

        int left = 0;
        int ans = 0;
        int maxfreq = 0;

        for (int right = 0; right < s.size(); right++) {
            mp[s[right]]++;
            maxfreq = max(maxfreq, mp[s[right]]);

            while (k < (right - left + 1) - maxfreq) {
                mp[s[left++]]--;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
