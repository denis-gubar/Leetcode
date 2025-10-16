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
    long long countPairs(int N, vector<vector<int>>& edges) {
        long long result = 0;
        UnionFind uf(N);
        for (vector<int> const& e : edges)
        {
            int const& V = e[0];
            int const& U = e[1];
            uf.checkedUnite(V, U);
        }
        vector<long long> A;
        for (int i = 0; i < N; ++i)
            if (uf.root(i) == i)
                A.push_back(uf.groupSize[i]);
        long long total = accumulate(A.begin(), A.end(), 0LL);
        for (long long x : A)
            result += x * (total - x);
        return result / 2;
    }
};
