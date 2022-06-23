static int F[1001][1001];
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int N = s.size();
        memset(F, 63, sizeof(F));
        for (int i = 0; i <= N; ++i)
            F[i][0] = 0;
        for(int i = 0; i < N; ++i)
            for(int j = 0; j <= i; ++j)
                F[i + 1][j + 1] = min({ F[i + 1][j + 1], F[i][j + 1], F[i][j] * 2 + (s[i] == '1')});
        int result = 0;
        for (int j = 0; j <= N; ++j)
            if (F[N][j] <= k)
                result = j;
        return result;
    }
};
