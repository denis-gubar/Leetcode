class Solution {
public:
    int const MOD = 1'000'000'007;
    int countSubMultisets(vector<int>& nums, int L, int R) {
        map<int, int> M;
        M[0] = 0;
        for (int x : nums)
            ++M[x];
        int N = R + 1;
        vector<int> F(N);
        int Z = M[0];
        F[0] = Z + 1;
        M.erase(M.find(0));
        for (auto [x, k] : M)
        {
            vector<int> FN = F;
            int last = x * k % MOD;
            vector<int> balance(x);
            for (int i = x; i < N; ++i)
            {
                int cur = i % x;
                balance[cur] = (balance[cur] + F[i - x]) % MOD;
                FN[i] = (FN[i] + balance[cur]) % MOD;
                if (i >= last)
                    balance[cur] = (balance[cur] - F[i - last] + MOD) % MOD;
            }
            F = move(FN);
        }
        long long result = 0;
        for (int i = L; i <= R; ++i)
            result += F[i];
        return result % MOD;
    }
};
