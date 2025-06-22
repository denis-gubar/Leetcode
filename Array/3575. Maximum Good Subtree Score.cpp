static int MOD = 1'000'000'007;
static long long F[500];
static short masks[500];
class Solution {
public:
    int goodSubtreeSum(vector<int>& vals, vector<int>& par) {
        int const N = vals.size();
        vector<vector<int>> children(N);
        vector<map<short, long long>> M(N);
        for (int V = 1; V < N; ++V)
            children[par[V]].push_back(V);
        memset(F, 0, sizeof(F));
        memset(masks, 0, sizeof(masks));
        for (int V = 0; V < N; ++V)
        {
            M[V][0] = 0;
            int x = vals[V];
            short& mask = masks[V];
            while (x > 0)
            {
                int d = x % 10;
                if (mask & (1 << d))
                    mask = 0, vals[V] = 0, x = 0;
                else
                    mask |= 1 << d, x /= 10;
            }
        }
        long long result = 0;
        auto dfs = [&](this auto const& self, int V) -> void
            {
                int const& P = par[V];
                for (int U : children[V])
                    self(U);
                for (auto const [mask, value] : M[V])
                {
                    if (mask & masks[V])
                        continue;
                    M[V][mask | masks[V]] = max(M[V][mask | masks[V]], value + vals[V]);
                }
                for (auto const [mask, value] : M[V])
                {
                    if (F[V] < value)
                        F[V] = value;
                    if (P < 0)
                        continue;
                    for (auto const [maskP, valueP] : M[P])
                    {
                        if (maskP & mask)
                            continue;
                        M[P][maskP | mask] = max(M[P][maskP | mask], valueP + value);
                    }
                }
            };
        dfs(0);
        for (int V = 0; V < N; ++V)
            result += F[V] % MOD;
        return result % MOD;
    }
};
