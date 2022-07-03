class LFUCache {
public:
    LFUCache(int capacity): capacity(capacity), t(0) {
        
    }
    
    int get(int key) {
        if (auto it = values.find(key); capacity > 0 && it != values.end())
        {
            int value, count, last;
            tie(value, count, last) = it->second;
            S.erase(make_tuple(count, last, key));
            last = ++t;
            ++count;
            S.emplace(count, last, key);
            it->second = make_tuple(value, count, last);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (capacity == 0)
            return;        
        if (auto it = values.find(key); it != values.end())
        {            
            int old_value, count, last;
            tie(old_value, count, last) = it->second;
            S.erase(make_tuple(count, last, key));
            last = ++t;
            ++count;
            it->second = make_tuple(value, count, last);
            S.emplace(count, last, key);
        }
        else 
        {
            if (S.size() == capacity)
            {
                int remove_count, remove_last, remove_key;
                tie(remove_count, remove_last, remove_key) = *S.begin();
                S.erase(S.begin());
                values.erase(remove_key);
            }
            int last = ++t;
            int count = 1;
            values[key] = make_tuple(value, count, last);
            S.emplace(count, last, key);
        }
    }
    int capacity, t;
    //count, last, key
    set<tuple<int, int, int>> S;
    //key value, count, last
    unordered_map<int, tuple<int, int, int>> values;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
