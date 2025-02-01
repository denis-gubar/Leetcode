static long long F[50'000][3][3];
class Solution {
public:
    long long minCost(int N, vector<vector<int>>& cost) {
        memset(F, 1, sizeof(F));
        long long result = F[0][0][0];
        auto update = [](long long& x, long long value)
            {
                if (x > value)
                    x = value;
            };
        for (int a = 0; a < 3; ++a)
            for (int b = 0; b < 3; ++b)
                if (a != b)
                    F[0][a][b] = cost[0][a] + cost[N - 1][b];
        for(int i = 1; i < N / 2; ++i)
            for(int a = 0; a < 3; ++a)
                for (int b = 0; b < 3; ++b)
                    if (a != b)
                        for(int c = 0; c < 3; ++c)
                            if (a != c)
                                for(int d = 0; d < 3; ++d)
                                    if (b != d && c != d)
                                        update(F[i][c][d], F[i - 1][a][b] + cost[i][c] + cost[N - i - 1][d]);
        for (int a = 0; a < 3; ++a)
            for (int b = 0; b < 3; ++b)
                update(result, F[N / 2 - 1][a][b]);
        return result;
    }
};
