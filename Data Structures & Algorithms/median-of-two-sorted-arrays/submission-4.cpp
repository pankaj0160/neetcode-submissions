class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;  // we assume A is shorter array
        vector<int>& B = nums2;

        int total = A.size() + B.size();
        int half = (total+1) / 2;

        if (A.size() > B.size()) swap(A, B);

        int l = 0;
        int r = A.size();

        while (l <= r) {
            int i = (l + r) / 2;  // guess where to cut for A
            int j = half - i;     // calculate where to cut B to match the size

            // now 4 boundary values : elements just before and after the cut point in both the
            // arrays :
            int Aleft = (i <= 0) ? INT_MIN : A[i - 1];  // if i = 0 then there is no left element in
                                                        // A, so use a very small number
            int Aright =
                (i >= A.size()) ? INT_MAX : A[i];  // if i is at the end, there is no right element
                                                   // in A, so use very large number
            int Bleft = (j <= 0) ? INT_MIN : B[j - 1];
            int Bright = (j >= B.size()) ? INT_MAX : B[j];

            // now we guessed the partition but  this partition can be wrong so we should check for
            // correct or not :
            if (Aleft <= Bright && Bleft <= Aright) {
                if (total % 2 != 0)
                    return max(Aleft, Bleft);
                else
                    return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            }
            else if(Aleft > Bright) r = i-1;
            else l = i+1;
        }
        return -1;
    }
};
