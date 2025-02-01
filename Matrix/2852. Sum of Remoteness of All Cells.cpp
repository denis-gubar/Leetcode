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
    long long sumRemoteness(vector<vector<int>>& grid) {
        long long result = 0;
        long long total = 0;
        int const N = grid.size();
        UnionFind UF(N * N);
        for(int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (grid[i][j] > 0)
                {
                    total += grid[i][j];
                    if (i < N - 1 && grid[i + 1][j] > 0)
                        UF.checkedUnite((i + 1) * N + j, i * N + j);
                    if (j < N - 1 && grid[i][j + 1] > 0)
                        UF.checkedUnite(i * N + j + 1, i * N + j);
                }
        unordered_map<int, long long> M;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (grid[i][j] > 0)
                    M[UF.root(i * N + j)] += grid[i][j];
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (grid[i][j] > 0)
                    result += total - M[UF.root(i * N + j)];
        return result;
    }
};
