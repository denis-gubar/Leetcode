class Solution {
public:
    vector<int> calc(vector<vector<int>> const& edges)
    {
        int const N = edges.size() + 1;
        vector<int> result(N, -1);
        vector<vector<int>> connectivity(N);
        for (vector<int> const& e : edges)
        {
            int const& V = e[0], U = e[1];
            connectivity[V].push_back(U);
            connectivity[U].push_back(V);
        }
        queue<int> Q;
        vector<bool> visited(N);
        visited[0] = true;
        Q.push(0); Q.push(0);
        result[0] = 0;
        while (!Q.empty())
        {
            int const V = Q.front(); Q.pop();
            int const K = Q.front(); Q.pop();
            for (int U : connectivity[V])
                if (!visited[U])
                {
                    visited[U] = true;
                    Q.push(U); Q.push(1 - K);
                    result[U] = 1 - K;
                }
        }
        return result;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int const N = edges1.size() + 1, M = edges2.size() + 1;
        vector<int> result(N);
        vector<int> A = calc(edges1), B = calc(edges2);
        vector<int> PA{ 0, 0 }, PB{ 0, 0 };
        for (int V = 0; V < N; ++V)
            ++PA[A[V]];
        for (int V = 0; V < M; ++V)
            ++PB[B[V]];
        int const delta = max(PB[0], PB[1]);
        for (int V = 0; V < N; ++V)
            result[V] = PA[A[V]] + delta;
        return result;
    }
};
