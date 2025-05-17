class Solution {
public:
    int minReorder(int N, vector<vector<int>>& connections) {
        vector<vector<int>> connectivity(N);
        for (int i = 0; i < N - 1; ++i)
        {
            int const& V = connections[i][0];
            int const& U = connections[i][1];
            connectivity[V].push_back(U);
            connectivity[U].push_back(V + N);
        }
        int result = 0;
        function<void(int, int)> dfs = [&](int V, int P) -> void
            {
                for (int NU : connectivity[V])
                {
                    int const U = NU % N;
                    if (U == P)
                        continue;
                    if (NU == U)
                        ++result;
                    dfs(U, V);
                }
            };
        dfs(0, -1);
        return result;
    }
};
