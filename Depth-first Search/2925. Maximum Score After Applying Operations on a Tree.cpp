static long long F[20'001][2];
class Solution {
public:
    vector<vector<int>> tree;
    vector<int> values;
    int N;
    long long calc(int V, bool flag = false)
    {
        long long& result = F[V][flag];
        if (result < 0)
        {
            long long best = 0, best2 = 0;
            if (!flag)
            {
                if (!tree[V].empty())
                {
                    best = values[V];
                    for (int U : tree[V])
                        best += calc(U, false);
                    for (int U : tree[V])
                        best2 += calc(U, true);
                }
            }
            else
            {
                best = values[V];
                for (int U : tree[V])
                    best += calc(U, true);
            }
            result = max(best, best2);
        }
        return result;
    }
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        long long result = 0;
        memset(F, -1, sizeof(F));
        N = values.size();
        this->values = values;
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
            for (int U : connectivity[V])
                if (!visited[U])
                {
                    visited[U] = true;
                    Q.push(U);
                    tree[V].push_back(U);
                }
        }
        return calc(0);
    }
};
