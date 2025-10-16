class Solution {
public:
    bool hasMatch(string s, string p) {
        int pos = p.find('*');
        int const N = s.size(), P = p.size();
        for (int i = 0; i + P - 1 <= N; ++i)
            if (equal(s.begin() + i, s.begin() + i + pos, p.begin(), p.begin() + pos) &&
                s.find(p.substr(pos + 1), i + pos) != string::npos)
                return true;
        return false;
    }
};
