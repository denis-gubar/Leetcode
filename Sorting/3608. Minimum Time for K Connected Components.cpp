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
    int minTime(int N, vector<vector<int>>& edges, int K) {
        auto calc = [&edges, N, K](int m)
            {
                UnionFind UF(N);
                for (vector<int> const& e : edges)
                {
                    int const& V = e[0];
                    int const& U = e[1];
                    int const& T = e[2];
                    if (T > m)
                        UF.checkedUnite(V, U);
                }
                int count = 0;
                for (int V = 0; V < N; ++V)
                    count += V == UF.root(V);
                return count >= K;
            };
        if (calc(0))
            return 0;
        int a = 0, b = 1'000'000'000;
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
