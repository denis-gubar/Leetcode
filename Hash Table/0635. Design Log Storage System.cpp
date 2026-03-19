static const vector<string> F{ "Year", "Month", "Day", "Hour", "Minute", "Second" };
class LogSystem {
public:
    vector<int> split(const string& s, char delimeter = ':')
    {
        vector<int> result;
        istringstream ss(s);
        for (string token; !ss.eof(); )
        {
            getline(ss, token, delimeter);
            result.push_back(stoi(token));
        }
        return result;
    }
    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {
        M.insert({ split(timestamp), id });
    }
    
    vector<int> retrieve(string start, string end, string granularity) {
        vector<int> A = split(start);
        vector<int> B = split(end);
        int pos = find(F.begin(), F.end(), granularity) - F.begin();
        A.resize(pos + 1);
        B.resize(pos + 1);
        ++B.back();
        vector<int> result;
        for (auto it = M.lower_bound(A); it != M.end() && it->first < B; ++it)
            result.push_back(it->second);
        return result;
    }
    multimap<vector<int>, int> M;
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */
