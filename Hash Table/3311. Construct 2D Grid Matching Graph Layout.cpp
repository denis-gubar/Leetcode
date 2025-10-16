class Solution {
public:
    vector<vector<int>> constructGridLayout(int N, vector<vector<int>>& edges) {
        vector<vector<int>> result;
        vector<vector<int>> connectivity(N);
        int const E = edges.size();
        for (int i = 0; i < E; ++i)
        {
            int const& V = edges[i][0];
            int const& U = edges[i][1];
            connectivity[V].push_back(U);
            connectivity[U].push_back(V);
        }
        vector<vector<int>> A(5);
        for (int i = 2; i < 5; ++i)
            A[i].reserve(N);
        for (int i = 0; i < N; ++i)
            A[connectivity[i].size()].push_back(i);
        vector<bool> visited(N);
        if (!A[1].empty())
        {
            result.push_back({});
            result[0].reserve(N);
            int const V = A[1][0];
            result[0].push_back(V);
            visited[V] = true;
            queue<int> Q;
            Q.push(V);
            while (!Q.empty())
            {
                int V = Q.front(); Q.pop();
                for(int U : connectivity[V])
                    if (!visited[U])
                    {
                        result[0].push_back(U);
                        Q.push(U);
                        visited[U] = true;
                    }
            }
        }
        else
        {
            vector<vector<int>> Lines(2);
            vector<vector<bool>> visiteds;
            Lines[0].reserve(N);
            Lines[1].reserve(N);
            int const V = A[2][0];
            visited[V] = true;
            visiteds.push_back(visited);
            visiteds.push_back(visited);
            queue<int> Q;
            for (int z = 0; z < 2; ++z)
            {
                int const U = connectivity[V][z];
                visiteds[z][U] = true;
                Lines[z].push_back(V);
                Lines[z].push_back(U);
                if (connectivity[U].size() == 3)
                    Q.push(U);
                while (!Q.empty())
                {
                    int V = Q.front(); Q.pop();
                    for (int U : connectivity[V])
                        if (!visiteds[z][U] && connectivity[U].size() != 4)
                        {
                            Lines[z].push_back(U);
                            if (connectivity[U].size() == 3)
                                Q.push(U);
                            visiteds[z][U] = true;
                        }
                }
            }
            vector<int> Line;
            if (Lines[1].size() == 2)
                Line = Lines[1], visited = visiteds[1];
            else
                Line = Lines[0], visited = visiteds[0];
            int L = Line.size();
            result.reserve(N / L);
            result.push_back(Line);
            for (int k = 1; k < N / L; ++k)
            {
                result.push_back(vector<int>(L));
                for (int U : connectivity[result[k - 1][0]])
                    if (!visited[U])
                    {
                        result[k][0] = U;
                        visited[U] = true;
                        break;
                    }
                for (int j = 1; j < L; ++j)
                {
                    unordered_set<int> S;
                    int V = result[k][j - 1];
                    int W = result[k - 1][j];
                    for (int U : connectivity[V])
                        if (!visited[U])
                            S.insert(U);
                    for (int U : connectivity[W])
                        if (!visited[U] && !S.insert(U).second)
                        {
                            result[k][j] = U;
                            visited[U] = true;
                            break;
                        }
                }
            }
        }
        return result;
    }
};
