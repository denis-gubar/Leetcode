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
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int Q = queries.size();
        vector<int> result(Q);
        int N = grid.size(), M = grid[0].size();
        UnionFind UF(N * M);
        vector<pair<int, int>> P;
        vector<int> dx{ -1, 0, 1, 0 };
        vector<int> dy{ 0, -1, 0, 1 };
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                P.push_back({ grid[i][j], i * M + j });
        sort(P.begin(), P.end());
        P.push_back({ 1'000'001, -1 });
        map<int, int> X;
        for (int i = 0; i < N * M; )
        {
            int k = i;
            for (; P[k].first == P[i].first; ++k)
            {
                int x = P[k].second / M, y = P[k].second % M;
                for (int z = 0; z < 4; ++z)
                {
                    int nx = x + dx[z];
                    int ny = y + dy[z];
                    if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] <= grid[x][y])
                        UF.checkedUnite(P[k].second, nx * M + ny);
                }
            }
            if (grid[0][0] <= P[i].first)
                X[P[i].first] = UF.groupSize[UF.root(0)];
            i = k;
        }
        for (int i = 0; i < Q; ++i)
            if (queries[i] > grid[0][0])
            {
                auto it = X.lower_bound(queries[i]);
                if (it != X.begin())
                {
                    --it;
                    result[i] = it->second;
                }
            }
        return result;
    }
};
