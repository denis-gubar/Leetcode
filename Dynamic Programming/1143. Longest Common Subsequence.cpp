static int F[1'001][1'001];
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int const N = text1.size(), M = text2.size();
        memset(F, 0, sizeof(F));
        for(int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                F[i + 1][j + 1] = max({ F[i + 1][j], F[i][j + 1], F[i][j] + (text1[i] == text2[j]) });
        return F[N][M];
    }
};
