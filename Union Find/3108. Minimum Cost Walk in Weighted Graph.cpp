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
    vector<int> minimumCost(int N, vector<vector<int>>& edges, vector<vector<int>>& query) {
        int Q = query.size();
        UnionFind UF(N);
        for (vector<int> const& e : edges)
        {
            int const& V = e[0];
            int const& U = e[1];
            UF.checkedUnite(V, U);
        }
        unordered_map<int, int> M;
        for (vector<int> const& e : edges)
        {
            int const& V = e[0];
            int const& U = e[1];
            int const& W = e[2];
            int const R = UF.root(V);
            if (M.find(R) == M.end())
                M[R] = W;
            else
                M[R] &= W;
        }
        vector<int> result(Q, -1);
        for (int q = 0; q < Q; ++q)
        {
            int const& V = query[q][0];
            int const& U = query[q][1];
            if (V == U)
            {
                result[q] = 0;
                continue;
            }
            int const R = UF.root(V);
            if (R == UF.root(U))                
                result[q] = M[R];
        }
        return result;
    }
};
