class TimeMap {
   public:
    unordered_map<string, vector<pair<int, string>>> keystore;
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        keystore[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        auto& values = keystore[key];

        int i = 0;
        int j = values.size() - 1;
        string result = "";

        while (i <= j) {
            int m = i + (j - i) / 2;

            if (values[m].first <= timestamp) {
                result = values[m].second;
                i = m + 1;  // we can get greater value as well
            } else
                j = m - 1;
        }
        return result;
    }
};
