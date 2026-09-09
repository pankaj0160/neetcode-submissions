class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (nums[m] == target)
                return m;
            else if (nums[l] <= nums[m]) {  // left side of mid is sorted
                // check if target lies within left array
                if (target <= nums[m] && target >= nums[l])
                    r = m - 1;
                else
                    l = m + 1;
            } else {  // right side of mid is sorted
                // check if target lies within right array
                if (target >= nums[m] && target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        return -1;
    }
};
