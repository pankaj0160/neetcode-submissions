class Solution {
   public:
    bool canfinish(vector<int>& piles, int h, long long k) {
        long long hours = 0;
        for (auto p : piles) {
            hours += (p + k - 1) / k; // same as math.ceil(p/k)
            if (hours > h) return false;
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // search space for k is from 1 to max(piles)

        // now we have to search in this sorted search space of k

        long long lo = 1;
        long long hi = *max_element(piles.begin(), piles.end());

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;

            if (canfinish(piles, h, mid))
                hi = mid;  // mid works but we want smaller value so shrink from the right
            else
                lo = mid + 1;
        }
        return (int)hi;
    }
};
