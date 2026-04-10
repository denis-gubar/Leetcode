static int const MOD = 1'000'000'007;
static int F[100'001];
class Solution {
public:
    static int power(int x, int n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        long long result = x;
        long long extra = 1;
        while (n > 1)
        {
            if (n % 2)
            {
                extra *= result;
                extra %= MOD;
            }
            result *= result;
            result %= MOD;
            n /= 2;
        }
        return result * extra % MOD;
    }
    static int div(int x)
    {
        return power(x, MOD - 2);
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int const N = nums.size(), Q = queries.size();
        copy(nums.begin(), nums.end(), &F[0]);
        F[N] = 1;
        int result = 0;
        //K, X, V
        vector<tuple<int, int, int>> T;
        T.reserve(Q * 2);
        for (vector<int> const& q : queries)
        {
            int const& L = q[0];
            int R = q[1];
            int const& K = q[2];
            int const& V = q[3];
            R = L + (R - L) / K * K + K;
            int const invV = div(V);
            T.emplace_back(K, L, V);
            T.emplace_back(K, R, invV);
        }
        sort(T.begin(), T.end());
        for (int i = 0; i < 2 * Q; )
        {            
            int j = i;
            unordered_map<int, int> A, B, VAL;
            while (j < 2 * Q && get<0>(T[i]) == get<0>(T[j]))
            {
                auto const& [K, X, V] = T[j];
                int const REM = X % K;
                if (auto it = VAL.find(X); it == VAL.end())
                    VAL[X] = V;
                else
                    it->second = 1LL * it->second * V % MOD;
                if (auto it = A.find(REM); it == A.end())
                    A[REM] = X;
                B[REM] = X;
                ++j;
            }
            for (auto [REM, X] : A)
            {
                long long V = 1;
                for (int pos = X, endPos = B[REM]; pos < endPos; pos += get<0>(T[i]))
                {
                    if (auto it = VAL.find(pos); it != VAL.end())
                        V = V * it->second % MOD;
                    F[pos] = V * F[pos] % MOD;
                }
            }
            i = j; 
        }
        for (int i = 0; i < N; ++i)
            result ^= F[i];
        return result;
    }
};
