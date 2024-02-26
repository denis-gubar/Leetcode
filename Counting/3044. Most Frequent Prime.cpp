static bool isInit = false;
static vector<bool> isPrime(1'000'000, 1);
static int divs[100'001][20];
static void init()
{
    if (!isInit)
    {
        isInit = true;
        memset(divs, 0, sizeof(divs));
        isPrime[1] = isPrime[0] = 0;
        for (int i = 2; i * i < 1'000'000; ++i)
            if (isPrime[i])
                for (int k = i * i; k < 1'000'000; k += i)
                    isPrime[k] = 0;
    }
}
class Solution {
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        init();
        unordered_map<int, int> A;
        int N = mat.size(), M = mat[0].size();
        for(int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                for(int dx = -1; dx <= 1; ++dx)
                    for (int dy = -1; dy <= 1; ++dy)
                    {
                        if (dx == 0 && dy == 0)
                            continue;
                        int value = mat[i][j];
                        for (int k = 1; dx * k + i >= 0 && dx * k + i < N && dy * k + j >= 0 && dy * k + j < M; ++k)
                        {
                            value = 10 * value + mat[dx * k + i][dy * k + j];
                            if (value > 10 && isPrime[value])
                                ++A[value];
                        }
                    }
        int result = -1;
        int best = 0;
        for (auto [key, value] : A)
            if (value > best)
                best = value, result = key;
            else if (value == best && result < key)
                result = key;
        return result;
    }
};
