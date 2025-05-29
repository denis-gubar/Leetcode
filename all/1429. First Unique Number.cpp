class FirstUnique {
public:
    int id;
    FirstUnique(vector<int>& nums): id(0) {
        for (int x : nums)
            add(x);
    }
    
    int showFirstUnique() {
        if (S.begin() == S.end())
            return -1;
        return S.begin()->second;
    }
    
    void add(int value) {
        ++id;
        if (M.find(value) == M.end())
        {
            S.insert({ id, value });
            M[value] = id;
        }
        else
            S.erase({ M[value], value });
    }
    unordered_map<int, int> M;
    set<pair<int, int>> S;
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
