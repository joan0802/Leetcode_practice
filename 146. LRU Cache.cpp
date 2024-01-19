class LRUCache {
public:
    int size = 0;
    int cnt = 0;
    unordered_map<int, pair<int, list<int>::iterator>> mp;
    list<int> q;
    LRUCache(int capacity) {
        size = capacity;
    }
    void Update(int key) {
        auto it = mp[key].second;
        q.erase(it);
        q.push_back(key);
        mp[key].second = --q.end();
    }
    int get(int key) {
        if(mp.count(key)) {
            Update(key);
            return mp[key].first;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key) == 1) {
            Update(key);
            mp[key] = {value, --q.end()};
        }
        else if(cnt == size) {
            mp.erase(q.front());
            q.pop_front();
            q.push_back(key);
            mp[key] = {value, --q.end()};
        }
        else {
            q.push_back(key);
            mp[key] = {value, --q.end()};
            cnt++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */