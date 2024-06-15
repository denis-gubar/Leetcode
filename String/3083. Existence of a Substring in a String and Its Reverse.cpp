class Solution {
public:
    bool isSubstringPresent(string s) {
        string r(s.rbegin(), s.rend());
        string_view st(s), sr(r);
        int N = s.size();
        for (int start = 0; start <= N - 2; ++start)
            if (sr.find(s.substr(start, 2)) != string::npos)
                return true;
        return false;
    }
};
