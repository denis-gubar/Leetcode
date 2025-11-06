static int F[150][151];
static int A[150][150];
static int const MOD = 1'000'000'007;
class Solution {
public:
    int countCoprime(vector<vector<int>>& mat) {
        int result = 0;
        memset(F, 0, sizeof(F));
        int const N = mat.size(), M = mat[0].size();
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                A[i][j] = mat[i][j];
        auto add = [](int& x, int value)
            {
                x += value;
                if (x >= MOD)
                    x -= MOD;
            };
        for (int j = 0; j < M; ++j)
            ++F[0][A[0][j]];
        for (int i = 1; i < N; ++i)
            for (int g = 1; g <= 150; ++g)
                if (F[i - 1][g])
                    for (int j = 0; j < M; ++j)
                        add(F[i][gcd(g, A[i][j])], F[i - 1][g]);
        return F[N - 1][1];
    }
};
