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
    vector<bool> pathExistenceQueries(int N, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int const Q = queries.size();
        vector<bool> result(Q);
        UnionFind UF(N);
        for (int i = 1; i < N; ++i)
            if (nums[i] - nums[i - 1] <= maxDiff)
                UF.unite(i, i - 1);
        for (int q = 0; q < Q; ++q)
        {
            int const& V = queries[q][0];
            int const& U = queries[q][1];
            result[q] = UF.root(V) == UF.root(U);
        }
        return result;
    }
};
