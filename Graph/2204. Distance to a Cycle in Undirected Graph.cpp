class Solution {
public:
    vector<int> distanceToCycle(int N, vector<vector<int>>& edges) {
        vector<int> result(N);
        vector<vector<int>> connectivity(N);
        vector<int> nodeDegree(N);
        vector<bool> isInCycle(N, true), visited(N);
        for (vector<int> const& e : edges)
        {
            int const& V = e[0], U = e[1];
            connectivity[V].push_back(U);
            connectivity[U].push_back(V);
            ++nodeDegree[V], ++nodeDegree[U];
        }
        queue<int> Q;
        for (int V = 0; V < N; ++V)
            if (nodeDegree[V] == 1)
                Q.push(V);
        while (!Q.empty())
        {
            int const V = Q.front(); Q.pop();
            isInCycle[V] = false;
            visited[V] = true;
            for(int const U : connectivity[V])
                if (!visited[U])
                {
                    if (--nodeDegree[U] == 1)
                        Q.push(U);
                }
        }
        visited.assign(N, false);
        for (int V = 0; V < N; ++V)
            if (isInCycle[V])
                Q.push(V), visited[V] = true;
        while (!Q.empty())
        {
            int const V = Q.front(); Q.pop();
            for(int const U: connectivity[V])
                if (!visited[U])
                {
                    visited[U] = true; result[U] = result[V] + 1;
                    Q.push(U);
                }
        }
        return result;
    }
};

