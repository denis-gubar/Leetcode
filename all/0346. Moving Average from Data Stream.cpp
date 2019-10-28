class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size): windowSize(0), sum(0), data(vector<int>(size)), pos(0) {}
    
    double next(int val) {
        sum += val - data[pos];
        data[pos] = val;
        ++pos;
        pos %= data.size();
        if (windowSize < data.size())
            ++windowSize;
        return 1.0 * sum / windowSize;
    }
    int pos;
    int sum;
    int windowSize;
    vector<int> data;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */