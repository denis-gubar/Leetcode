class Solution {
public:
    bool checkContradictions(vector<vector<string>>& equations, vector<double>& values) {
        unordered_map<string, int> M;
        vector<vector<pair<int, double>>> connectivity;
        connectivity.reserve(200);
        int const E = equations.size();
        for (int e = 0; e < E; ++e)
        {
            vector<string> const& eq = equations[e];
            string const& A = eq[0];
            string const& B = eq[1];
            if (M.find(A) == M.end())
                M[A] = M.size(), connectivity.push_back({});
            if (M.find(B) == M.end())
                M[B] = M.size(), connectivity.push_back({});
            connectivity[M[A]].push_back({ M[B], values[e] });
            connectivity[M[B]].push_back({ M[A], 1.0 / values[e] });
        }
        int const N = M.size();
        vector<bool> visited(N);
        vector<double> X(N);
        queue<int> Q;
        for (int V = 0; V < N; ++V)
            if (!visited[V])
            {
                visited[V] = true;
                X[V] = 1.0;
                Q.push(V);
                while (!Q.empty())
                {
                    int V = Q.front(); Q.pop();
                    for(auto [U, ratio] : connectivity[V])
                        if (!visited[U])
                        {
                            visited[U] = true;
                            X[U] = X[V] / ratio;
                            Q.push(U);
                        }
                        else
                        {
                            if (abs(X[U] - X[V] / ratio) > 1e-8)
                                return true;
                        }
                }
            }
        return false;
    }
};
