class Solution {
public:
    int residuePrefixes(string s) {
        int result = 0;
        unordered_set<char> S;
        int const N = s.size();
        for (int i = 0; i < N; ++i)
        {
            S.insert(s[i]);
            if (S.size() == (i + 1) % 3)
                ++result;
        }
        return result;
    }
};
