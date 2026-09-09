class Solution {
   public:
    int findMin(vector<int>& nums) {
        if (nums[0] < nums[nums.size() - 1]) return nums[0];

        int i = 0;
        int j = nums.size() - 1;

        while (i < j) {
            int m = i + (j - i) / 2;

            if (nums[m] > nums[j])
                i = m + 1;
            else
                j = m;
        }
        return nums[j];
    }
};
