static int const MOD = 1'000'000'007;
class Solution {
public:
    int power(int x, int n)
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
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int const N = edges.size() + 1;
        vector<vector<int>> connectivity(N + 1);
        for (int i = 0; i < N - 1; ++i)
        {
            int const& V = edges[i][0];
            int const& U = edges[i][1];
            connectivity[V].push_back(U);
            connectivity[U].push_back(V);
        }
        vector<int> depth(N + 1);
        depth[0] = -1;
        function<void(int, int)> dfs = [&](int V, int P) -> void
            {
                depth[V] = depth[P] + 1;
                for (int U : connectivity[V])
                    if (U != P)
                        dfs(U, V);
            };
        dfs(1, 0);
        int x = *max_element(depth.begin(), depth.end());
        return power(2, x - 1);
    }
};
