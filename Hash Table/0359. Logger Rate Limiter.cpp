class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        while (!q.empty() && q.front() + 10 <= timestamp)
        {
            S.erase(S.find(qs.front()));
            q.pop(); qs.pop();
        }
        if (S.find(message) != S.end())
            return false;
        S.insert(message);
        q.push(timestamp); qs.push(message);
        return true;
    }
    queue<int> q;
    queue<string> qs;
    multiset<string> S;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */