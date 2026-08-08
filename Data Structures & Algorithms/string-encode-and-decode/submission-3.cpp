class Solution {
public:

    string encode(vector<string>& strs) {

        string en = "";

        for (auto x : strs) {
            en.append(to_string(x.size()));
            en.push_back('#');
            en.append(x);
        }

        return en;
    }

    vector<string> decode(string s) {

        vector<string> ans;

        int i = 0;

        while (i < s.size()) {

            int j = i;

            // Find '#'
            while (s[j] != '#') {
                j++;
            }

            // Extract length
            int size = stoi(s.substr(i, j - i));

            // Move i to beginning of actual string
            i = j + 1;

            // Extract string
            ans.push_back(s.substr(i, size));

            // Move i to next encoded string
            i = i + size;
        }

        return ans;
    }
};