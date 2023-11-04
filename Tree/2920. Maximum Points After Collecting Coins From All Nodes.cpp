static int F[100'001][15];
static int const INF = -2139062144;
class Solution {
public:
    vector<vector<int>> tree;
    vector<int> coins;
    int N;
    int fine;
    int calc(int V, int K)
    {
        int& result = F[V][K];
        if (result == INF)
        {
            int result1 = (coins[V] >> K) - fine;
            int result2 = coins[V] >> (K + 1);
            for (int U : tree[V])
                result1 += calc(U, K);
            for (int U : tree[V])
                result2 += calc(U, min(14, K + 1));
            result = max(result1, result2);
        }
        return result;
    }
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        this->coins = coins;
        N = coins.size();
        fine = k;
        vector<vector<int>> connectivity(N);
        tree = vector<vector<int>>(N);
        for (int i = 0; i < N - 1; ++i)
        {
            int const& V = edges[i][0];
            int const& U = edges[i][1];
            connectivity[V].push_back(U);
            connectivity[U].push_back(V);
        }
        queue<int> Q;
        vector<bool> visited(N);
        Q.push(0);
        visited[0] = true;
        while (!Q.empty())
        {
            int V = Q.front(); Q.pop();
            for(int U : connectivity[V])
                if (!visited[U])
                {
                    visited[U] = true;
                    Q.push(U);
                    tree[V].push_back(U);
                }
        }
        memset(F, -128, sizeof(F));
        return calc(0, 0);
    }
};
