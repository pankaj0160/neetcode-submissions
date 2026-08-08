class Solution {
public:

    string encode(vector<string>& strs) {

        if(strs.empty()) return "";

        string en = "";

        for(auto x : strs) {
            en.append(to_string(x.size()));
            en.push_back('#');
            en.append(x);
        }
        return en;
    }

    vector<string> decode(string s) {

        if(s.empty()) return {};

        vector<string>ans;

        for(int i = 0; i<s.size(); i++){

            int j = i;
            
            while(s[j] != '#') j++;

            // extract size :
            int size = stoi(s.substr(i, j-i));

            // extract substring
            i = j+1;
            j = j + size;

            ans.push_back(s.substr(i, size));
            i = j;
        }
        return ans;
    }
};
