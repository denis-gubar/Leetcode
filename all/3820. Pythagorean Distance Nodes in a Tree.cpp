class Solution {
public:
    int specialNodes(int N, vector<vector<int>>& edges, int X, int Y, int Z) {
        int result = 0;
        vector<vector<int>> connectivity(N);
        for (vector<int> const& e : edges)
        {
            int const& V = e[0];
            int const& U = e[1];
            connectivity[V].push_back(U);
            connectivity[U].push_back(V);
        }
        auto bfs = [N, &connectivity](int V, vector<int>& F) -> void
            {
                vector<bool> visited(N);
                queue<int> Q;
                visited[V] = true;
                Q.push(V); Q.push(0);
                while (!Q.empty())
                {
                    int const V = Q.front(); Q.pop();
                    int const T = Q.front(); Q.pop();
                    F[V] = T;
                    for(int U: connectivity[V])
                        if (!visited[U])
                        {
                            visited[U] = true;
                            Q.push(U); Q.push(T + 1);
                        }
                }
            };
        vector<int> A(N), B(N), C(N);
        bfs(X, A);
        bfs(Y, B);
        bfs(Z, C);
        for (int V = 0; V < N; ++V)
        {
            vector<long long> S{ 1LL * A[V] * A[V], 1LL * B[V] * B[V], 1LL * C[V] * C[V] };
            sort(S.begin(), S.end());
            result += S[0] + S[1] == S[2];
        }
        return result;
    }
};
