class Solution {
public:
    int reachableNodes(int N, vector<vector<int>>& edges, vector<int>& restricted) {
        int result = 0;
        vector<vector<int>> connectivity(N);
        vector<bool> visited(N);
        for (int x : restricted)
            visited[x] = true;
        for (vector<int> const& e : edges)
        {
            int const& V = e[0];
            int const& U = e[1];
            connectivity[V].push_back(U);
            connectivity[U].push_back(V);
        }
        queue<int> Q;
        Q.push(0); visited[0] = true;
        while (!Q.empty())
        {
            ++result;
            int V = Q.front(); Q.pop();
            for(int U : connectivity[V])
                if (!visited[U])
                {
                    visited[U] = true;
                    Q.push(U);
                }
        }
        return result;
    }
};
