static long long F[100'001][6];
class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        long long result = 0;
        a.push_back(0);
        memset(F, -50, sizeof(F));
        F[0][0] = 0;
        int const N = b.size();
        for(int i = 0; i < N; ++i)
            for (int j = 0; j < 5; ++j)
            {
                F[i + 1][j] = max(F[i + 1][j], F[i][j]);
                F[i + 1][j + 1] = max(F[i + 1][j + 1], F[i][j] + 1LL * a[j] * b[i]);
            }
        return F[N][4];
    }
};
