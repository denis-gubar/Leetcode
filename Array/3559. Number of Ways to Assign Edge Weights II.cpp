static int const MOD = 1'000'000'007;
class Solution {
public:
    int power(int x, int n)
    {
        if (x == 0)
            return 0;
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
public:
    struct UnionFind
    {
        vector<int> id, groupSize;
        UnionFind(int N) : id(vector<int>(N)), groupSize(vector<int>(N, 1))
        {
            iota(id.begin(), id.end(), 0);
        }
        int root(int x)
        {
            while (x != id[x])
                x = id[x] = id[id[x]];
            return x;
        }
        bool find(int p, int q)
        {
            return root(p) == root(q);
        }
        void unite(int p, int q)
        {
            p = root(p), q = root(q);
            if (groupSize[p] < groupSize[q])
                id[p] = q, groupSize[q] += groupSize[p];
            else
                id[q] = p, groupSize[p] += groupSize[q];
        }
        void checkedUnite(int p, int q)
        {
            if (!find(p, q))
                unite(p, q);
        }
    };
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int const N = edges.size() + 1, Q = queries.size();
        vector<vector<pair<int, int>>> connectivityQ(N + 1);
        for (int q = 0; q < Q; ++q)
        {
            int const& V = queries[q][0];
            int const& U = queries[q][1];
            if (V != U)
            {
                connectivityQ[V].push_back({ U, q });
                connectivityQ[U].push_back({ V, q });
            }
        }
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
        UnionFind UF(N + 1);
        vector<bool> visited(N + 1);
        vector<int> ancestors(N + 1);
        vector<int> result(Q);
        function<void(int)> dfsLCA = [&](int V) -> void
            {
                visited[V] = true;
                ancestors[V] = V;
                for(int U : connectivity[V])
                    if (!visited[U])
                    {
                        dfsLCA(U);
                        UF.checkedUnite(V, U);
                        ancestors[UF.root(V)] = V;
                    }
                for (pair<int, int> P : connectivityQ[V])
                {
                    int const& QU = P.first;
                    int const& q = P.second;
                    if (visited[QU])
                    {
                        int const LCA = ancestors[UF.root(QU)];
                        result[q] = power(2, (depth[V] - depth[LCA]) + (depth[QU] - depth[LCA]) - 1);
                    }
                }
            };
        dfsLCA(1);
        return result;
    }
};
