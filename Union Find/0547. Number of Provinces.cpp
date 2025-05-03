class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int result = 0;
        int const N = isConnected.size();
        vector<bool> visited(N);
        function<void(int)> dfs = [&](int V) -> void
            {
                visited[V] = true;
                for (int U = 0; U < N; ++U)
                    if (!visited[U] && isConnected[V][U])
                        dfs(U);
            };
        for(int V = 0; V < N; ++V)
            if (!visited[V])
            {
                ++result;
                dfs(V);
            }
        return result;
    }
};
