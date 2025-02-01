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
    int magnificentSets(int N, vector<vector<int>>& edges) {
        int result = 0;
        UnionFind UF(N);
        vector<bool> isVisited(N), isOdd(N);
        vector<vector<int>> connectivity(N);
        for (vector<int> const& e : edges)
        {
            int const V = e[0] - 1, U = e[1] - 1;
            UF.checkedUnite(V, U);
            connectivity[V].push_back(U);
            connectivity[U].push_back(V);
        }
        for (int V = 0; V < N; ++V)
            if (!isVisited[V])
            {
                isVisited[V] = true;
                queue<pair<int, bool>> Q;
                Q.push({ V, false });
                while (!Q.empty())
                {
                    pair<int, bool> P = Q.front(); Q.pop();
                    int const& V = P.first;
                    for (int U : connectivity[V])
                        if (!isVisited[U])
                        {
                            isVisited[U] = true;
                            Q.push({ U, isOdd[U] = !isOdd[V] });
                        }
                }
            }
        for (int V = 0; V < N; ++V)
            for (int U : connectivity[V])
                if (isOdd[V] == isOdd[U])
                    return -1;
        auto bfs = [&connectivity, N](int V) -> pair<int, int>
            {
                pair<int, int> result{ V, 1 };
                vector<bool> visited(N);
                visited[V] = true;
                queue<int> Q;
                Q.push(V); Q.push(-1); Q.push(1);
                while (!Q.empty())
                {
                    int const V = Q.front(); Q.pop();
                    int const P = Q.front(); Q.pop();
                    int const level = Q.front(); Q.pop();
                    for (int U : connectivity[V])
                        if (U != P && !visited[U])
                        {
                            visited[U] = true;
                            if (result.second <= level)
                                result = { U, level + 1 };
                            Q.push(U); Q.push(V); Q.push(level + 1);
                        }
                }                
                return result;
            };
        vector<int> M(N);
        for (int V = 0; V < N; ++V)
            M[UF.root(V)] = max(M[UF.root(V)], bfs(V).second);
        for (int V = 0; V < N; ++V)
            if (V == UF.root(V))
                result += M[V];
        return result;
    }
};
