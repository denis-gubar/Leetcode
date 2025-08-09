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
    int countIslands(vector<vector<int>>& grid, int K) {
        int result = 0;
        int const N = grid.size(), M = grid[0].size(), NM = N * M;
        UnionFind UF(NM);
        array const dx{ -1, 0, 1, 0 };
        array const dy{ 0, -1, 0, 1 };
        for(int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
            {
                if (grid[i][j] == 0)
                    continue;
                for (int z = 0; z < 4; ++z)
                {
                    int const nx = i + dx[z];
                    int const ny = j + dy[z];
                    if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny])
                        UF.checkedUnite(nx * M + ny, i * M + j);
                }
            }
        unordered_map<int, int> A;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
            {
                if (grid[i][j] == 0)
                    continue;
                int const key = UF.root(i * M + j);
                A[key] = (1'000'000LL * K + A[key] + grid[i][j]) % K;
            }
        for (auto [key, value] : A)
            if (value == 0)
                ++result;
        return result;
    }
};
