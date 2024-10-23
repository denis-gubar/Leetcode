static short F[3'001][3'002];
class Solution {
public:
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int const N = source.size(), P = pattern.size(), T = targetIndices.size();
        vector<bool> target(N);
        for (int i = 0; i < T; ++i)
            target[targetIndices[i]] = true;
        memset(F, -1, sizeof(F));
        F[0][0] = 0;
        for(int i = 0; i < N; ++i)
            for (int j = 0; j <= P; ++j)
                if (F[i][j] >= 0)
                {
                    if (j == P)
                    {
                        F[i + 1][j] = max(F[i + 1][j], F[i][j]);
                        if (target[i])
                            F[i + 1][j] = max<short>(F[i + 1][j], F[i][j] + 1);
                        continue;
                    }
                    bool const flag = source[i] == pattern[j];
                    F[i + 1][j + flag] = max(F[i + 1][j + flag], F[i][j]);
                    if (target[i])
                        F[i + 1][j] = max<short>(F[i + 1][j], F[i][j] + 1);
                }
        return F[N][P];
    }
};
