class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // hashmap 

        unordered_set<int>mp;

        for(int num : nums){
            if(mp.find(num) != mp.end()) return num ;
            mp.insert(num);
        }
        return -1;
    }
};
