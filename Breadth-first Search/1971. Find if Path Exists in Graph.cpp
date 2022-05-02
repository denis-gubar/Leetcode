class Solution {
public:
    bool validPath(int N, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> connectivity(N);
        for (vector<int> const& e : edges)
        {
			int const& V = e[0];
			int const& U = e[1];
            connectivity[V].push_back(U);
            connectivity[U].push_back(V);
        }
        vector<bool> visited(N);
        visited[source] = true;
        queue<int> Q;
        Q.push(source);
        while (!Q.empty())
        {
            int V = Q.front(); Q.pop();
            if (V == destination)
                return true;
            for(int U : connectivity[V])
                if (!visited[U])
                {
                    visited[U] = true;
                    Q.push(U);
                }
            connectivity[V].clear();
        }
        return false;
    }
};
