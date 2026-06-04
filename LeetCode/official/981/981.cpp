class TimeMap {
private:
    map<string, vector<pair<int, string>>> myMap;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        myMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = myMap.find(key);
        if (it != myMap.end())
            return binarySearch(it, timestamp);
        else return "";
    }

    string binarySearch(auto it, int timestamp) {
        int start = 0;
        int end = it->second.size() - 1;
        int checked = 0;
        string value = "";
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (it->second[mid].first == timestamp) return (it->second[mid].second);
            
            else if (it->second[mid].first > timestamp) end = mid - 1;
            else if (it->second[mid].first < timestamp) start = mid + 1;
            if (it->second[mid].first <= timestamp) {
                if (timestamp > checked) {
                    checked = it->second[mid].first;
                    value = it->second[mid].second;
                }
            }
        }
        return (value);
    }
};
