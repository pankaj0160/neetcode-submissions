class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> vec;

        for (int i = 0; i < n; i++) {
            vec.push_back({position[i], (double)(target - position[i]) / speed[i]});
        }

        sort(vec.begin(), vec.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
            return a.first > b.first;
        });

        // now iterating the vector for counting fleet :
        stack<pair<int, double>> st;

        for (int i = 0; i < vec.size(); i++) {
            if (st.empty()) st.push(vec[i]);

            // comparing current car to stack top car
            if (vec[i].second <= st.top().second)
                continue;
            else
                st.push(vec[i]);
        }
        return st.size();
    }
};
