class Solution {
public:
    int peopleAwareOfSecret(int N, int delay, int forget) {
        constexpr int MOD = 1'000'000'007;
        vector<long long> F(N + 1);
        F[1] = 1;
        for (int i = 1; i <= N; ++i)
        {
            F[i] %= MOD;
            for (int j = i + delay; j <= N && j - i < forget; ++j)
                F[j] += F[i];            
        }
        return accumulate(F.end() - forget, F.end(), 0LL) % MOD;
    }
};
