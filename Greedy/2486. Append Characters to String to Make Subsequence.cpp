class Solution {
public:
    int appendCharacters(string s, string t) {
        int N = s.size(), M = t.size();
        int j = 0;
        for (int i = 0; i < N; ++i)
        {
            if (s[i] == t[j])
            {
                ++j;
                if (j == M)
                    return 0;
            }
        }
        return M - j;
    }
};
