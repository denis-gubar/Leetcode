static int empty[2][102];
static int have[2][102];
class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        int result = 0;
        memset(::empty, -100, sizeof(::empty));
        memset(::have, -100, sizeof(::have));
        ::empty[0][0] = 0;
        int const N = prices.size();
        for (int i = 0; i < N; ++i)
        {
            int const& price = prices[i];
            int const current = i % 2;
            int const next = 1 - current;
            for (int j = 0; j <= K; ++j)
            {
                if (j == 0)
                    ::empty[next][j] = ::empty[current][j];
                ::empty[next][j + 1] = max(::empty[current][j + 1], ::have[current][j] + price);
                ::have[next][j] = max(::have[current][j], ::empty[current][j] - price);
            }
        }
        for (int i = 1; i <= K; ++i)
            result = max(result, ::empty[N % 2][i]);
        return result;
    }
};
