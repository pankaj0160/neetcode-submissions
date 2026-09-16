class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array to optimize binary search range
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        
        if (A.size() > B.size()) {
            // Swap so A is always the smaller one
            A = nums1; 
            B = nums2;
            // Note: In LeetCode, passing by reference allows us to just swap the 
            // vectors themselves or the references. 
            // To be safe and clear, we can just swap the vectors if we want, 
            // but the logic below relies on 'A' being the one we search on.
            // Let's swap the actual vectors to keep 'A' smaller.
            swap(A, B);
        } else {
            // If A was already smaller, we just assign references correctly.
            // However, the initial assignment 'A = nums1' might have been swapped.
            // Let's re-assign to be sure.
            // Actually, the line below is safer:
            // We just need to ensure the variable 'A' points to the smaller vector.
            // Since we did swap(A, B) above, A is now the smaller one.
            // But wait, the original A and B were references to nums1 and nums2.
            // Swapping references swaps what they point to.
            // This is correct.
        }
        
        // If the swap above didn't work as expected due to reference semantics, 
        // let's do it explicitly on the vectors passed in to be absolutely sure.
        // BUT, the standard efficient way is:
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1); // Recursive swap
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        
        // The left partition must contain (total + 1) / 2 elements.
        // This ensures the median is always in the left partition for odd totals.
        int halfLen = (total + 1) / 2;
        
        int left = 0;
        int right = m; // Binary search on the smaller array
        
        while (left <= right) {
            // i is the number of elements from nums1 in the left partition
            int i = (left + right) / 2;
            // j is the number of elements from nums2 in the left partition
            int j = halfLen - i;
            
            // Get the 4 boundary values.
            // Use INT_MIN/INT_MAX for cases where a partition is empty.
            int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRight1 = (i == m) ? INT_MAX : nums1[i];
            
            int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRight2 = (j == n) ? INT_MAX : nums2[j];
            
            // Check if we found the correct partition
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // Found!
                // If total is odd, median is the max of the left partition
                if (total % 2 != 0) {
                    return max(maxLeft1, maxLeft2);
                } else {
                    // If total is even, median is the average of the max of left 
                    // and min of right partitions.
                    // Use (double) to ensure floating point division.
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                }
            }
            else if (maxLeft1 > minRight2) {
                // We are too far to the right in nums1. Go left.
                right = i - 1;
            }
            else {
                // We are too far to the left in nums1. Go right.
                left = i + 1;
            }
        }
        
        return 0.0; // Should never reach here for valid inputs
    }
};