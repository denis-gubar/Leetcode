class MyCalendarThree {
public:
    MyCalendarThree(): result(0) {
        
    }
    
    int book(int start, int end) {
        A.push_back({start, end});
        if (M.find(start) == M.end())
        {
            int current = 0;
            for(auto [a, b] : A)
                if (a <= start && start < b)
                    ++current;
            result = max(result, current);
            M[start] = current;
        }
        else
            result = max(result, ++M[start]);
        for(auto it = M.upper_bound(start); it != M.end() && it->first < end; ++it)
        {
            ++it->second;
            result = max(result, it->second);
        }
        return result;
    }
    vector<pair<int, int>> A;
    map<int, int> M;
    int result;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */