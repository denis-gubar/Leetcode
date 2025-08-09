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
    int minCost(int N, vector<vector<int>>& edges, int K) {
        int a = -1, b = 1'000'000;
        sort(edges.begin(), edges.end(), [](vector<int> const& a, vector<int> const& b)
            {
                return a[2] < b[2];
            }
        );
        auto calc = [&edges, N, K](int m) -> bool
            {
                int count = 0;
                UnionFind UF(N);
                for (vector<int> const& e : edges)
                {
                    int const& W = e[2];
                    if (W > m)
                        break;
                    int const& V = e[0];
                    int const& U = e[1];
                    UF.checkedUnite(V, U);
                }
                for (int V = 0; V < N; ++V)
                    if (V == UF.root(V))
                        ++count;
                return count <= K;
            };
        while (a + 1 < b)
        {
            int m = (a + b) / 2;
            if (calc(m))
                b = m;
            else
                a = m;
        }
        return b;
    }
};
