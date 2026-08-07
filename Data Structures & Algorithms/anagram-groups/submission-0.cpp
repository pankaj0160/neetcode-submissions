class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;

        unordered_map<string, vector<string>>mp;
        string sorted = "";

        for(string s : strs){
            sorted = s;
            sort(sorted.begin(), sorted.end());
            mp[sorted].push_back(s);
        }

        for(auto x : mp) {
            ans.push_back(x.second);
        }
        return ans;
    }
};
