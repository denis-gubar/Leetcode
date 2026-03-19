class Solution {
public:
    int minOperations(string s) {
        string t = s;
        sort(t.begin(), t.end());
        if (s == t)
            return 0;
        if (s[0] == t[0] || s.back() == t.back())
            return 1;
        if (s[0] == t.back() && s.back() == t[0])
        {
            if (s.size() == 2)
                return -1;
            unordered_map<char, int> M;
            for (char c : s)
                ++M[c];
            if (M[s[0]] == 1 && M[s.back()] == 1)
                return 3;
        }
        return 2;
    }
};
