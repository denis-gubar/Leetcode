class Solution {
public:
    bool isSubsequence(string s, string t) {
        int N = s.size(), M = t.size();
        int b = 0;
        for (int a = 0; a < M && b < N; ++a)
            b += s[b] == t[a];
        return b == N;
    }
};
