class DataStream {
public:
    DataStream(int value, int k): count(0), value(value), k(k) {
        
    }
    
    bool consec(int num) {
        if (num == value)
            ++count;
        else
            count = 0;
        return count >= k;
    }
    int count;
    int k;
    int value;
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
