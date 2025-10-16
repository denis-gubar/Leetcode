static long long D[100'000];
class Solution {
public:
    int minIncrease(int N, vector<vector<int>>& edges, vector<int>& cost) {
        int result = 0;
        vector<vector<int>> connectivity(N);
        for (int i = 0; i < N - 1; ++i)
        {
            int const& V = edges[i][0];
            int const& U = edges[i][1];
            connectivity[V].push_back(U);
            connectivity[U].push_back(V);
        }
        vector<bool> visited(N);
        vector<bool> isLeaf(N, true);
        memset(D, 0, sizeof(D));
        long long sum = 0;
        auto dfs = [&](this auto const& self, int V) -> void
            {
                sum += cost[V];
                D[V] = sum;
                visited[V] = true;
                for(int U : connectivity[V])
                    if (!visited[U])
                    {
                        isLeaf[V] = false;
                        self(U);
                    }
                sum -= cost[V];
            };
        dfs(0);
        visited.assign(N, false);
        auto dfs2 = [&](this auto const& self, int V) -> void
            {
                visited[V] = true;
                vector<long long> A;
                for (int U : connectivity[V])
                    if (!visited[U])
                    {
                        self(U);
                        A.push_back(D[U]);
                    }
                sort(A.begin(), A.end());
                int const N = A.size();
                for (int i = 0; i < N; ++i)
                    if (A[i] != A.back())
                        ++result;
                if (!A.empty())
                    D[V] = A.back();
            };
        dfs2(0);
        return result;
    }
};
