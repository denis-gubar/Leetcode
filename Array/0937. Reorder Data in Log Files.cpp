class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), [](string const& a, string const& b)
            {
                int A = a.find(' '), B = b.find(' ');
                bool isDigitA = isdigit(a[A + 1]);
                bool isDigitB = isdigit(b[B + 1]);
                if (isDigitA != isDigitB)
                    return isDigitA < isDigitB;
                if (!isDigitA && !isDigitB)
                    if (a.substr(A) == b.substr(B))
                        return a < b;
                    else
                        return a.substr(A) < b.substr(B);
                return false;                
            });
        return logs;            
    }
};