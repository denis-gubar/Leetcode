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
    vector<vector<int>> rotate(vector<vector<int>> const& A)
    {
        int N = A.size();
        int M = A[0].size();
        vector<vector<int>> result(M, vector<int>(N));
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j)
                result[i][j] = A[N - 1 - j][i];
        return result;
    }
    int numDistinctIslands2(vector<vector<int>>& grid) {
        vector<int> const dx{ 0, -1, 0, 1 };
        vector<int> const dy{ -1, 0, 1, 0 };
        vector<vector<int>> G(grid);
        map<vector<pair<int, int>>, int> Islands;
        int N = G.size();
        int M = G[0].size();
        int islandCount = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (G[i][j] == 1)
                {
                    vector<pair<int, int>> path;
                    queue<int> Q;
                    Q.push(i); Q.push(j);
                    ++islandCount;
                    G[i][j] = 1 + islandCount;
                    while (!Q.empty())
                    {
                        int x = Q.front(); Q.pop();
                        int y = Q.front(); Q.pop();
                        for (int z = 0; z < 4; ++z)
                        {
                            int nx = x + dx[z];
                            int ny = y + dy[z];
                            if (nx >= 0 && nx < N && ny >= 0 && ny < M && G[nx][ny] == 1)
                            {
                                G[nx][ny] = G[i][j];
                                Q.push(nx); Q.push(ny);
                            }
                        }
                    }
                }
        UnionFind uf(islandCount);
        vector<vector<int>> A(G);
        auto calc = [&uf, &dx, &dy, &A, &Islands]()
        {
            vector<vector<int>> G(A);
            int N = G.size();
            int M = G[0].size();            
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < M; ++j)
                    if (G[i][j])
                    {
                        vector<pair<int, int>> path;
                        queue<int> Q;
                        Q.push(i); Q.push(j);
                        int V = G[i][j] - 2;
                        G[i][j] = 0;
                        path.push_back({ 0, 0 });
                        while (!Q.empty())
                        {
                            int x = Q.front(); Q.pop();
                            int y = Q.front(); Q.pop();
                            for (int z = 0; z < 4; ++z)
                            {
                                int nx = x + dx[z];
                                int ny = y + dy[z];
                                if (nx >= 0 && nx < N && ny >= 0 && ny < M && G[nx][ny])
                                {
                                    G[nx][ny] = 0;
                                    Q.push(nx); Q.push(ny);
                                    path.push_back({ nx - i, ny - j });
                                }
                            }
                        }
                        if (auto it = Islands.find(path); it != Islands.end())
                            uf.checkedUnite(V, it->second);
                        else
                            Islands[path] = V;
                    }
        };        
        for (int k = 0; k < 4; ++k)
        {
            calc();
            A = rotate(A);
        }        
        reverse(A.begin(), A.end());
        for (int k = 0; k < 4; ++k)
        {
            calc();
            A = rotate(A);
        }
        int result = 0;
        for (int i = 0; i < islandCount; ++i)
            result += (uf.root(i) == i);
        return result;
    }
};
