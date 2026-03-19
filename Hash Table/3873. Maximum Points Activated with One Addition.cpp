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
    int maxActivated(vector<vector<int>>& points) {
        int const N = points.size();
        UnionFind UF(N);
        unordered_map<int, int> X, Y;
        for (int i = 0; i < N; ++i)
        {
            int const& x = points[i][0];
            int const& y = points[i][1];
            if (auto it = X.find(x); it == X.end())
                X[x] = i;
            else
                UF.unite(i, it->second);
            if (auto it = Y.find(y); it == Y.end())
                Y[y] = i;
            else
                UF.checkedUnite(i, it->second);
        }
        vector<int> groups;
        groups.reserve(N);
        for (int i = 0; i < N; ++i)
            if (UF.root(i) == i)
                groups.push_back(UF.groupSize[i]);
        sort(groups.begin(), groups.end(), greater{});
        int const M = groups.size();
        if (M < 3)
            return N + 1;
        return groups[0] + groups[1] + 1;
    }
};
