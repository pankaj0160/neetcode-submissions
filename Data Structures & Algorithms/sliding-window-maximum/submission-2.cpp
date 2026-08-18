class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        priority_queue<pair<int, int>>heap;
        vector<int>output;

        for(int i = 0; i<nums.size(); i++){
            heap.push({nums[i], i});

            if(i >= k-1){ // if window size becomes k
                while(heap.top().second <= i-k) heap.pop(); // pop elements from heap outside the window
                output.push_back(heap.top().first);
            }
        }
        return output;
    }
};
