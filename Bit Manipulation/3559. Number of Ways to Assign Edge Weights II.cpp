static int const MOD = 1'000'000'007;
static int const MAX_N = 100'000;
static int P2[MAX_N];
static bool isInit = false;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        P2[0] = 1;
        for (int i = 1; i < 100'000; ++i)
        {
            P2[i] = P2[i - 1] << 1;
            if (P2[i] >= MOD)
                P2[i] -= MOD;
        }        
    }
}
static int ancestors[MAX_N + 1];
static int depth[MAX_N + 1];
class Solution {
public:
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
        init();
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
        depth[1] = 0;
        UnionFind UF(N + 1);
        vector<bool> visited(N + 1);
        vector<int> result(Q);
        auto dfsLCA = [&](this const auto& self, int V) -> void
            {
                visited[V] = true;
                ancestors[V] = V;
                for (int U : connectivity[V])
                    if (!visited[U])
                    {
                        depth[U] = depth[V] + 1;
                        self(U);
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
                        result[q] = P2[(depth[V] - depth[LCA]) + (depth[QU] - depth[LCA]) - 1];
                    }
                }
            };
        dfsLCA(1);
        return result;
    }
};

