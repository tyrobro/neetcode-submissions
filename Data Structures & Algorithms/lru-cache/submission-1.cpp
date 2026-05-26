class LRUCache {
public:
    int capacity;
    list<pair<int, int>> lruList;
    
    unordered_map<int, list<pair<int, int>>::iterator> mp;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        
        lruList.splice(lruList.begin(), lruList, mp[key]);
        
        return mp[key]->second;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key]->second = value;
            lruList.splice(lruList.begin(), lruList, mp[key]);
            return;
        }
        
        if (lruList.size() == capacity) {
            int keyToDelete = lruList.back().first;
            lruList.pop_back(); 
            mp.erase(keyToDelete); 
        }
        
        lruList.push_front({key, value});
        mp[key] = lruList.begin();
    }
};