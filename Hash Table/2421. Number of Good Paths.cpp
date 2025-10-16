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
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int result = 0;
        int N = vals.size();
        UnionFind UF(N);
        vals.push_back(1 << 30);
        vector<int> A(N + 1);
        iota(A.begin(), A.end(), 0);
        sort(A.begin(), A.end(), [&vals](int a, int b)
            {
                return vals[a] < vals[b];
            });
        vector<vector<int>> connectivity(N);
        for (int i = 0; i < edges.size(); ++i)
        {
            int const& V = edges[i][0];
            int const& U = edges[i][1];
            if (vals[V] > vals[U])
                connectivity[V].push_back(U);
            else
                connectivity[U].push_back(V);
        }
        for (int i = 0; i < N; )
        {
            int j = i;
            for (; vals[A[i]] == vals[A[j]]; ++j)
            {
                int const& V = A[j];
                for (int U : connectivity[V])
                    UF.checkedUnite(V, U);
            }
            unordered_map<int, int> groups;
            for (int k = i; k < j; ++k)
                ++groups[UF.root(A[k])];
            for (auto [key, val] : groups)
                result += val * (val + 1) / 2;
            i = j;
        }
        return result;
    }
};
