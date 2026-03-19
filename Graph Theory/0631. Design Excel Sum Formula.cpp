static int F[27 * 27];
static multiset<short> usedBy[27 * 27];
static multiset<short> formula[27 * 27];
class Excel {
public:
    short f(int row, char column)
    {
        return row * 27 + (column - 'A');
    }
    Excel(int height, char width): N(height), M(width - 'A' + 1) {
        memset(F, 0, sizeof(F));
        fill(&formula[0], &formula[0] + 27 * 27, multiset<short>{});
        fill(&usedBy[0], &usedBy[0] + 27 * 27, multiset<short>{});
    }
    
    void clearFormula(int row, char column)
    {
        short parentFormula = f(row, column);
        for (short key : formula[parentFormula])
            usedBy[key].erase(usedBy[key].find(parentFormula));
        formula[parentFormula].clear();
    }

    void set(int row, char column, int val) {
        clearFormula(row, column);
        short key = f(row, column);
        int delta = val - F[key];
        queue<pair<short, int>> Q;
        Q.push({ key, 1 });
        while (!Q.empty())
        {
            short key = Q.front().first;
            int count = Q.front().second;
            Q.pop();
            F[key] += delta * count;
            unordered_map<short, int> nextQ;
            for (short parentFormula : usedBy[key])
                nextQ[parentFormula] += count;
            for (auto [nextKey, nextCount] : nextQ)
                Q.push({ nextKey, nextCount });
        }        
    }
    
    int get(int row, char column) {
        return F[f(row, column)];
    }
    
    int sum(int row, char column, vector<string> numbers) {
        clearFormula(row, column);
        short parentFormula = f(row, column);
        int delta = -F[parentFormula];
        int result = 0;
        for (string const& val : numbers)
        {
            if (int pos = val.find(':'); pos != string::npos)
            {
                char a = val[0];
                char b = val[pos + 1];
                int x = 0;
                for (int i = 1; i < pos; ++i)
                    x = x * 10 + (val[i] - '0');
                int y = 0;
                for (int i = pos + 2, end = val.size(); i < end; ++i)
                    y = y * 10 + (val[i] - '0');
                for (int i = x; i <= y; ++i)
                    for (char c = a; c <= b; ++c)
                    {
                        short key = f(i, c);
                        formula[parentFormula].insert(key);
                        usedBy[key].insert(parentFormula);
                        result += F[key];
                    }
            }
            else
            {
                char a = val[0];
                int x = 0;
                for (int i = 1, end = val.size(); i < end; ++i)
                    x = x * 10 + (val[i] - '0');
                short key = f(x, a);
                formula[parentFormula].insert(key);
                usedBy[key].insert(parentFormula);
                result += F[key];
            }
        }
        delta += result;
        queue<pair<short, int>> Q;
        Q.push({ parentFormula, 1 });
        while (!Q.empty())
        {
            short key = Q.front().first;
            int count = Q.front().second;
            Q.pop();
            F[key] += delta * count;
            unordered_map<short, int> nextQ;
            for (short parentFormula : usedBy[key])
                nextQ[parentFormula] += count;
            for (auto [nextKey, nextCount] : nextQ)
                Q.push({ nextKey, nextCount });
        }
        return F[parentFormula];
    }
    int N, M;
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(height, width);
 * obj->set(row,column,val);
 * int param_2 = obj->get(row,column);
 * int param_3 = obj->sum(row,column,numbers);
 */
