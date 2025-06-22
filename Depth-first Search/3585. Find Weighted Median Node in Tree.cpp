static int const MAX_N = 100'000;
static int parents[MAX_N + 1];
static int ancestors[MAX_N + 1];
static int depth[MAX_N + 1];
static int LCA[MAX_N + 1];
static long long dist[MAX_N + 1];
class Solution {
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
    using Distance = int;
    vector<int> findMedian(int N, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int const Q = queries.size();
        vector<int> result(Q, -1);
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
        vector<vector<pair<int, Distance>>> connectivity(N + 1);
        for (int i = 0; i < N - 1; ++i)
        {
            int const& V = edges[i][0];
            int const& U = edges[i][1];
            int const& W = edges[i][2];
            connectivity[V].push_back({ U, W });
            connectivity[U].push_back({ V, W });
        }
        depth[0] = 0;
        dist[0] = 0;
        parents[0] = -1;
        UnionFind UF(N + 1);
        vector<bool> visited(N + 1);
        auto dfsLCA = [&](this const auto& self, int V) -> void
            {
                visited[V] = true;
                ancestors[V] = V;
                for (auto [U, W] : connectivity[V])
                    if (!visited[U])
                    {
                        parents[U] = V;
                        depth[U] = depth[V] + 1;
                        dist[U] = dist[V] + W;
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
                        LCA[q] = ancestors[UF.root(QU)];
                    }
                }
            };
        dfsLCA(0);
        vector<vector<int>> P(N);
        bool changed = true;
        for (int V = 1; V < N; ++V)
            P[V].push_back(parents[V]);
        int k = 1;
        while (changed)
        {
            changed = false;
            for (int i = 1; i < N; ++i)
                if (P[i].size() >= k && P[P[i][k - 1]].size() >= k)
                {
                    changed = true;
                    P[i].push_back(P[P[i][k - 1]][k - 1]);
                }
            ++k;
        }
        for (int q = 0; q < Q; ++q)
        {
            int const& V = queries[q][0];
            int const& U = queries[q][1];
            if (V == U)
            {
                result[q] = V;
                continue;
            }
            long long const first = dist[V] - dist[LCA[q]];
            long long const total = dist[V] + dist[U] - 2 * dist[LCA[q]];
            if (first + first >= total)
            {
                long long const t = (total + 1) / 2;
                int A = V, B = LCA[q];
                while (depth[B] + 1 < depth[A])
                {
                    int M = P[A][bit_width<unsigned int>(depth[A] - depth[B]) - 2];
                    if (dist[V] - dist[M] >= t)
                        B = M;
                    else
                        A = M;
                }
                result[q] = B;
            }
            else
            {
                long long const t = (total + 1) / 2;
                int A = U, B = LCA[q];
                while (depth[B] + 1 < depth[A])
                {
                    int M = P[A][bit_width<unsigned int>(depth[A] - depth[B]) - 2];
                    if (dist[M] - dist[LCA[q]] + first >= t)
                        A = M;
                    else
                        B = M;
                }
                result[q] = A;
            }
        }

        return result;
    }
};

