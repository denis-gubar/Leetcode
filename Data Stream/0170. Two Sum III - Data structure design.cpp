class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        ++M[number];
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(pair<int, int> p: M)
        {
            if (p.first + p.first == value)
            {
                if (p.second > 1)
                    return true;
                continue;
            }
            if (M.find(value - p.first) != M.end())
                return true;
        }
        return false;
    }
    unordered_map<int, int> M;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */