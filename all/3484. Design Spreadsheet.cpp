static int F[26][1'001];
class Spreadsheet {
public:
    pair<int, int> parse(string const& cell)
    {
        pair<int, int> result;
        result.first = cell[0] - 'A';
        result.second = stoi(cell.substr(1));
        return result;
    }
    Spreadsheet(int rows) {
        memset(F, 0, sizeof(F));
    }
    
    void setCell(string cell, int value) {
        pair<int, int> P = parse(cell);
        F[P.first][P.second] = value;
    }
    
    void resetCell(string cell) {
        pair<int, int> P = parse(cell);
        F[P.first][P.second] = 0;
    }
    
    int getValue(string formula) {
        int result = 0;
        string buffer;
        formula += '+';
        for (char c : formula)
        {
            if (c == '=')
                continue;
            else if (c == '+')
            {
                if (::isdigit(buffer[0]))
                    result += stoi(buffer);
                else
                {
                    pair<int, int> P = parse(buffer);
                    result += F[P.first][P.second];
                }
                buffer.clear();
            }
            else
                buffer += c;
        }
        return result;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
