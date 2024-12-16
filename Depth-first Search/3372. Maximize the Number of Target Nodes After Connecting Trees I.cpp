class Solution {
public:
    vector<int> calc(vector<vector<int>> const& edges, int K)
    {
        int const N = edges.size() + 1;
        vector<int> result(N);
        vector<vector<int>> connectivity(N);
        for (vector<int> const& e : edges)
        {
            int const& V = e[0], U = e[1];
            connectivity[V].push_back(U);
            connectivity[U].push_back(V);
        }
        queue<int> Q;
        for (int X = 0; X < N; ++X)
        {
            vector<bool> visited(N);
            visited[X] = true;
            Q.push(X); Q.push(K);
            while (!Q.empty())
            {
                int const V = Q.front(); Q.pop();
                int const K = Q.front(); Q.pop();
                if (K >= 0)
                    ++result[X];
                if (K == 0)
                    continue;
                for(int U : connectivity[V])
                    if (!visited[U])
                    {
                        visited[U] = true;
                        Q.push(U); Q.push(K - 1);
                    }
            }
        }
        return result;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int const N = edges1.size() + 1, M = edges2.size() + 1;
        vector<int> result(N);
        vector<int> A = calc(edges1, k), B = calc(edges2, k - 1);
        auto delta = *max_element(B.begin(), B.end());
        for (int V = 0; V < N; ++V)
            result[V] = A[V] + delta;
        return result;
    }
};
