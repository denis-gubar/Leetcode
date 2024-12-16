static int F[1'000][1'000];
class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int const N = fruits.size();
        int result = 0;
        memset(F, -1, sizeof(F));
        for (int i = 0; i < N; ++i)
            result += fruits[i][i];
        fruits[N - 1][N - 1] = 0;
        auto update = [](int& x, int value) ->void
            {
                if (x < value)
                    x = value;
            };
        {
            auto check = [N](int i, int j)
                {
                    return i >= 0 && i < N && j >= 0 && j < N && i + j >= N - 1 && i - j >= 0;
                };
            F[N - 1][0] = fruits[N - 1][0], fruits[N - 1][0] = 0;
            for (int j = 0; j < N - 1; ++j)
                for (int i = N - 1; i >= 0; --i)
                    if (check(i, j))
                    {
                        if (check(i - 1, j + 1))
                            update(F[i - 1][j + 1], F[i][j] + fruits[i - 1][j + 1]);
                        if (check(i, j + 1))
                            update(F[i][j + 1], F[i][j] + fruits[i][j + 1]);
                        if (check(i + 1, j + 1))
                            update(F[i + 1][j + 1], F[i][j] + fruits[i + 1][j + 1]);
                    }
        }
        {
            auto check = [N](int i, int j)
                {
                    return i >= 0 && i < N && j >= 0 && j < N && i + j >= N - 1 && i - j <= 0;
                };
            F[0][N - 1] = fruits[0][N - 1], fruits[0][N - 1] = 0;
            for (int i = 0; i < N - 1; ++i)
                for (int j = N - 1; j >= 0; --j)
                    if (check(i, j))
                    {
                        if (check(i + 1, j - 1))
                            update(F[i + 1][j - 1], F[i][j] + fruits[i + 1][j - 1]);
                        if (check(i + 1, j))
                            update(F[i + 1][j], F[i][j] + fruits[i + 1][j]);
                        if (check(i + 1, j + 1))
                            update(F[i + 1][j + 1], F[i][j] + fruits[i + 1][j + 1]);
                    }
        }
        return result + F[N - 1][N - 2] + F[N - 2][N - 1];
    }
};
