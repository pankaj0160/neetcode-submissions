class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // first method is combining both the array and then find the median of it

        int len1 = nums1.size();
        int len2 = nums2.size();

        vector<int> c(len1 + len2);

        copy(nums1.begin(), nums1.end(), c.begin());
        copy(nums2.begin(), nums2.end(), c.begin() + len1);

        sort(c.begin(), c.end());

        int len = c.size();

        if (len % 2 == 0) {
            return (c[len / 2 - 1] + c[len / 2]) / 2.0;
        } else
            return c[len / 2];
    }
};
