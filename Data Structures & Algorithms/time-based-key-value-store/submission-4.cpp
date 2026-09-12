class TimeMap {
   public:
    unordered_map<string, map<int, string>> m;
    TimeMap() {}

    void set(string key, string value, int timestamp) { m[key].insert({timestamp, value}); }

    string get(string key, int timestamp) {
        auto it = m[key].upper_bound(timestamp);  // find the first entry with timestamp > query

        // if we are at the beginning, no earliest timemstamp exists
        // otherwise step back to the last entry with timestamp <= query
        return it == m[key].begin() ? "" : prev(it)->second;
    }
};
