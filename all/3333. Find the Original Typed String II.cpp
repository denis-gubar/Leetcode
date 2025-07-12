static int const MOD = 1'000'000'007;
static int F[2'001][2'001];
static int B[2'001];
class Solution {
public:
    int possibleStringCount(string word, int K) {
        word += '$';
        char prev = '^';
        int count = 0;
        int const N = word.size();
        vector<int> A;
        A.reserve(N);
        for (char c : word)
            if (c == prev)
                ++count;
            else
            {
                if (count > 0)
                    A.push_back(count);
                count = 1, prev = c;
            }
        int const M = A.size();
        if (M >= K)
        {
            int result = 1;
            for (int x : A)
                result = 1LL * result * x % MOD;
            return result;
        }
        memset(F, 0, sizeof(F));
        auto add = [](int& x, int value)
            {
                x += value;
                if (x >= MOD)
                    x -= MOD;
                else if (x < 0)
                    x += MOD;
            };
        F[0][0] = 1;
        for (int i = 0; i < M; ++i)
        {
            memset(B, 0, sizeof(B));
            int balance = 0;
            for (int j = i; j <= K; ++j)
            {
                add(balance, B[j]);
                if (j + 1 <= K)
                    add(B[j + 1], F[i][j]);
                if (j + A[i] + 1 <= K)
                    add(B[j + A[i] + 1], -F[i][j]);
                add(F[i + 1][j], balance);
                if (j + A[i] > K)
                    add(F[i + 1][K], 1LL * (j + A[i] - K) * F[i][j] % MOD);
            }
        }
        return F[M][K];
    }
};

