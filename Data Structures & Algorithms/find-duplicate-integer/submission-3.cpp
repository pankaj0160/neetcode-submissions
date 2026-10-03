class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        // cycle detection algorithm : slow and fast pointer

        // detect cycle first :
        int slow = nums[0];
        int fast = nums[0];

        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }

        // find the entrance of the cycle :
        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
