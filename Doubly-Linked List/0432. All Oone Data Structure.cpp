class AllOne {
public:
    long long encode(string const& key) const
    {
        long long result = 0;
        for (int i = key.size() - 1; i >= 0; --i)
        {
            int const x = key[i] - '`';
            result = result * 27 + x;
        }
        return result;
    }
    string decode(long long key) const
    {
        string result;
        result.reserve(10);
        while (key > 0)
        {
            result += key % 27 + '`';
            key /= 27;
        }
        return result;
    }

    unordered_map<long long, int> M;
    set<pair<int, long long>> S;

    AllOne() {
        
    }
    
    void inc(string const& key) {
        long long const x = encode(key);
        int count = ++M[x];
        if (count > 1)
            S.erase({ count - 1, x });
        S.insert({ count, x });
    }
    
    void dec(string const& key) {
        long long const x = encode(key);
        int count = --M[x];
        S.erase({ count + 1, x });
        if (count > 0)
            S.insert({ count, x });
    }
    
    string getMaxKey() {
        if (S.empty()) return {};
        return decode(S.rbegin()->second);
    }
    
    string getMinKey() {
        if (S.empty()) return {};
        return decode(S.begin()->second);
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
