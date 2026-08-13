class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int left = 0; // starting of window 
        int ans = 0; // final ans

        unordered_set<int> st;  // keeps window characters

        for (int right = 0; right < s.size(); right++) {
            while (st.find(s[right]) != st.end()) {
                st.erase(s[left++]);
            }
            st.insert(s[right]);
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
