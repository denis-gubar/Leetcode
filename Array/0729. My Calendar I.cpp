class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = S.lower_bound({start, start});
        if (it != S.begin())
        {
            --it;
            if (it->second >= start)
                return false;
            ++it;
        }
        if (it != S.end() && it->first < end)
            return false;
        S.insert({start, end - 1});
        return true;
        
    }
    set<pair<int, int>> S;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */