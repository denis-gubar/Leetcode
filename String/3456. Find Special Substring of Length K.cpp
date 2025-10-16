class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int const N = s.size();
        for (int i = 0; i + k <= N; ++i)
        {
            string t = s.substr(i, k);
            sort(t.begin(), t.end());
            if (t[0] != t[k - 1])
                continue;
            if (i > 0 && s[i - 1] == s[i])
                continue;
            if (i + k < N && s[i + k] == s[i])
                continue;
            return true;
        }
        return false;
    }
};
