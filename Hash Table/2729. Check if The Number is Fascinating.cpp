class Solution {
public:
    bool isFascinating(int n) {
        string s = to_string(n) + to_string(2 * n) + to_string(3 * n);
        set<char> S(s.begin(), s.end());
        if (S.find('0') != S.end())
            return false;
        return S.size() == 9 && s.size() == 9;
    }
};
