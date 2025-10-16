static int const MOD = 1'000'000'007;
static int F[2'001][2'001];
class Solution {
public:
    int zigZagArrays(int N, int L, int R) {
        R -= L; //L = 0
        memset(F, 0, sizeof(F));
        for (int j = 0; j < R; ++j)
            F[0][j] = 1;
        auto add = [](int& x, int value)
            {
                x += value;
                if (x >= MOD)
                    x -= MOD;
            };
        for (int i = 1; i < N; ++i)
        {            
            int sum = 0;
            for (int j = 1; j <= R; ++j)
                add(sum, F[i - 1][j - 1]), add(F[i][R - j], sum);
        }
        int result = 0;
        for (int j = 0; j <= R; ++j)
            add(result, F[N - 1][j]);
        add(result, result);
        return result;
    }
};
