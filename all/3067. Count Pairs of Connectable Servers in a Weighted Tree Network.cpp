class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int N = edges.size() + 1;
        vector<int> result(N);
        vector<vector<pair<int, int>>> connectivity(N);
        for (vector<int> const& e : edges)
        {
            int const& V = e[0];
            int const& U = e[1];
            int const& W = e[2];
            connectivity[V].emplace_back(U, W);
            connectivity[U].emplace_back(V, W);
        }
        vector<int> A;
        A.reserve(N);
        for (int V = 0; V < N; ++V)
        {
            queue<int> Q;
            vector<bool> visited(N);
            vector<int> D(N);
            visited[V] = true;
            A.clear();
            for (auto [Z, W] : connectivity[V])
            {
                A.push_back(0);
                Q.push(Z); visited[Z] = true; D[Z] = W % signalSpeed;
                while (!Q.empty())
                {
                    int V = Q.front(); Q.pop();
                    if (D[V] == 0)
                        ++A.back();
                    for (auto [U, W] : connectivity[V])
                        if (!visited[U])
                        {
                            D[U] = (D[V] + W) % signalSpeed; visited[U] = true;
                            Q.push(U);
                        }
                }
                if (A.back() == 0)
                    A.pop_back();
            }
            if (A.size() > 1)
            {
                int total = accumulate(A.begin(), A.end(), 0);
                for (int x : A)
                    result[V] += x * (total - x);
            }
            result[V] /= 2;
        }
        return result;
    }
};
