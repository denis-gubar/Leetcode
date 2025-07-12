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
    vector<int> processQueries(int C, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        int const Q = queries.size();
        vector<int> result;
        result.reserve(Q);
        UnionFind UF(C + 1);
        vector<set<int>> S(C + 1);
        for (vector<int> const& con : connections)
        {
            int const& V = con[0];
            int const& U = con[1];
            UF.checkedUnite(V, U);
        }
        for (int V = 1; V <= C; ++V)
            S[UF.root(V)].insert(V);
        for (int q = 0; q < Q; ++q)
        {
            int const& type = queries[q][0];
            int const& X = queries[q][1];
            set<int>& R = S[UF.root(X)];
            if (type == 1)
            {
                if (R.empty())
                    result.push_back(-1);
                else
                {
                    auto it = R.find(X);
                    if (it != R.end())
                        result.push_back(X);
                    else
                        result.push_back(*R.begin());
                }
            }
            else
            {
                auto it = R.find(X);
                if (it != R.end())
                    R.erase(it);
            }
        }
        return result;
    }
};
