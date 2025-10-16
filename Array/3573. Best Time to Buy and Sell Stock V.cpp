static long long empty[2][502];
static long long have[2][502];
static long long haveS[2][502];
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int K) {
        long long result = 0;
        memset(::empty, -100, sizeof(::empty));
        memset(::have, -100, sizeof(::have));
        memset(::haveS, -100, sizeof(::haveS));
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
                ::empty[next][j + 1] = max({ ::empty[current][j + 1], ::have[current][j] + price, ::haveS[current][j] - price });
                ::have[next][j] = max(::have[current][j], ::empty[current][j] - price);
                ::haveS[next][j] = max(::haveS[current][j], ::empty[current][j] + price);
            }
        }
        for (int i = 1; i <= K; ++i)
            result = max(result, ::empty[N % 2][i]);
        return result;
    }
};
