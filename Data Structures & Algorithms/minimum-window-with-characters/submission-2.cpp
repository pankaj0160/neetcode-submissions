class Solution {
   public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (m == 0) return "";

        unordered_map<int, int> countT;

        for (int i = 0; i < m; i++) {
            countT[t[i]]++;
        }
        int need = countT.size();
        int have = 0;
        int ans = INT_MAX;
        pair<int, int> res = {-1, -1};  // storing starting and ending index of window

        int l = 0;
        unordered_map<int, int> window;

        for (int r = 0; r < n; r++) {
            char c = s[r];
            window[c]++;

            if (countT[c] == window[c]) have++;

            while (countT.count(s[l]) && have == need) {  // the window is valid

                if ((r - l + 1) < ans) {
                    ans = r - l + 1;
                    res = {l, r};
                }
                window[s[l]]--;

                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) have--;
                l++;
            }
        }
        return ans == INT_MAX ? "" : s.substr(res.first, ans);
    }
};
