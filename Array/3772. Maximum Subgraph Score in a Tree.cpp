class Solution {
public:
    vector<int> maxSubgraphScore(int N, vector<vector<int>>& edges, vector<int>& good) {
        vector<int> result(N);
        vector<bool> visited(N);
        edges.reserve(2 * N - 2);
        for (int i = 0; i < N - 1; ++i)
            edges.push_back(edges[i]), swap(edges.back()[0], edges.back()[1]);
        vector<vector<int>> connectivity(N);
        for (int E = 0; E < 2 * N - 2; ++E)
        {
            int const& V = edges[E][0];
            int const& U = edges[E][1];
            connectivity[V].push_back(E);
        }
        vector<int> D(2 * N - 2, -2);
        auto dfs = [&](this const auto& self, int E) -> int
            {
                if (D[E] >= -1)
                    return D[E];
                int const& U = edges[E][1];
                if (visited[U])
                {
                    int const NE = (E + N - 1) % (2 * N - 2);
                    return D[E] = result[U] - max(0, self(NE));
                }
                int current = 2 * good[U] - 1;
                for (int E2 : connectivity[U])
                    if (abs(E2 - E) != N - 1)
                        current += max(0, self(E2));
                current = max(current, -1);
                return D[E] = current;
            };
        for (int V = 0; V < N; ++V)
        {
            for (int E : connectivity[V])
                result[V] += max(0, dfs(E));
            result[V] += 2 * good[V] - 1;
            visited[V] = true;
        }
        return result;
    }
};
