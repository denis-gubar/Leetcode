class FrequencyTracker {
public:
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        auto it = M.find(number);
        if (it != M.end())
            F.erase(F.find(it->second));
        F.insert(++M[number]);
    }
    
    void deleteOne(int number) {
        if (auto it = M.find(number); it != M.end())
        {
            F.erase(F.find(it->second));
            if (it->second == 1)
                M.erase(it);
            else
                F.insert(--M[number]);
        }
    }
    
    bool hasFrequency(int frequency) {
        return F.find(frequency) != F.end();
    }
    unordered_map<int, int> M;
    unordered_multiset<int> F;
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
