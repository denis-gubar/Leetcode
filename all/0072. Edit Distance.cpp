static int F[501][501];
class Solution {
public:
    int minDistance(string word1, string word2) {
        int const N = word1.size(), M = word2.size();
        for (int i = 0; i <= N; ++i)
            F[i][0] = i;
        for (int j = 0; j <= M; ++j)
            F[0][j] = j;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                F[i + 1][j + 1] = min({ F[i][j + 1] + 1, F[i + 1][j] + 1, F[i][j] + (word1[i] != word2[j]) });
        return F[N][M];
    }
};
