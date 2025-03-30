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
    int numberOfComponents(vector<vector<int>>& properties, int K) {
        int const N = properties.size(), M = properties[0].size();
        UnionFind UF(N);
        vector<int> A;
        A.reserve(2 * N);
        for (int i = 0; i < N; ++i)
        {
            vector<int>& V = properties[i];
            sort(V.begin(), V.end());
            V.resize(unique(V.begin(), V.end()) - V.begin());
        }
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
            {
                A.clear();
                set_intersection(properties[i].begin(), properties[i].end(), properties[j].begin(), properties[j].end(), back_inserter(A));
                if (A.size() >= K)
                    UF.checkedUnite(i, j);
            }
        int result = 0;
        for (int i = 0; i < N; ++i)
            if (UF.root(i) == i)
                ++result;
        return result;
    }
};
