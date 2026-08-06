class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> f;

        for (int x : nums) {
            if (f.find(x) != f.end()) return true;
            f[x]++;
        }
        return false;
    }
};