static int const INF = 1 << 20;
class Solution {
public:
    int R;
    vector<vector<int>> children;
    int calc(int V)
    {
        int result = -1, total = 1;
        bool flag = true;
        for (int U : children[V])
        {
            int P = calc(U);
            total += P;
            if (result == -1)
                result = P;
            else if (result != P)
                flag = false;
        }
        R += flag;
        return total;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        R = 0;
        int const N = edges.size() + 1;
        vector<vector<int>> connectivity(N);
        children = vector<vector<int>>(N);
        for (int i = 0; i < N - 1; ++i)
        {
            int const& V = edges[i][0];
            int const& U = edges[i][1];
            connectivity[V].push_back(U);
            connectivity[U].push_back(V);
        }
        vector<bool> visited(N);
        visited[0] = true;
        queue<int> Q;
        Q.push(0);
        while (!Q.empty())
        {
            int V = Q.front(); Q.pop();
            for(int U : connectivity[V])
                if (!visited[U])
                {
                    visited[U] = true;
                    Q.push(U);
                    children[V].push_back(U);
                }
        }
        calc(0);
        return R;
    }
};
