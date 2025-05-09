class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int const N = equations.size(), Q = queries.size();
        vector<double> result(Q, -1.0);
        unordered_map<string, vector<pair<string, double>>> connectivity;
        for (int i = 0; i < N; ++i)
        {
            string const& V = equations[i][0];
            string const& U = equations[i][1];
            if (V != U)
            {
                connectivity[V].push_back({ U, values[i] });
                connectivity[U].push_back({ V, 1.0 / values[i] });
            }
        }
        unordered_set<string> visited;
        function<double(string, string, double)> dfs = [&](string V, string T, double K) -> double
            {
                if (V == T) return K;
                double result = -1.0;
                for(auto [U, X]: connectivity[V])
                    if (visited.insert(U).second)
                        result = max(result, dfs(U, T, X * K));
                return result;
            };
        for (int q = 0; q < Q; ++q)
        {
            string const& V = queries[q][0];
            string const& T = queries[q][1];
            if (connectivity.find(V) == connectivity.end() || connectivity.find(T) == connectivity.end())
                continue;
            visited.clear();
            result[q] = dfs(V, T, 1.0);
        }
        return result;
    }
};
