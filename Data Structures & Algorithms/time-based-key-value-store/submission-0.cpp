class TimeMap {
public:
    unordered_map<string, map<int, string>> m;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        m[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto iterator = m[key].upper_bound(timestamp);
        return iterator == m[key].begin() ? "" : prev(iterator)->second;
    }
};
