class Solution {
public:
    vector<vector<int>> children;
    vector<int> values;
    int k, N;
    pair<int, int> calc(int V)
    {
        pair<int, int> result{ 0, values[V] };
        for (int U : children[V])
        {
            pair<int, int> P = calc(U);
            result.first += P.first;
            result.second = (result.second + P.second) % k;
        }
        if (result.second == 0)
            ++result.first;
        return result;
    }
    int maxKDivisibleComponents(int N, vector<vector<int>>& edges, vector<int>& values, int k) {
        this->k = k;
        this->N = N;
        vector<vector<int>> connectivity(N);
        children = vector<vector<int>>(N);
        for (int& x : values)
            x %= k;
        this->values = values;
        for (vector<int> const& e : edges)
        {
            int const& V = e[0];
            int const& U = e[1];
            connectivity[V].push_back(U);
            connectivity[U].push_back(V);
        }
        queue<int> Q;
        vector<bool> visited(N);
        visited[0] = true;
        Q.push(0);
        while (!Q.empty())
        {
            int V = Q.front(); Q.pop();
            for (int U : connectivity[V])
                if (!visited[U])
                {
                    visited[U] = true;
                    children[V].push_back(U);
                    Q.push(U);
                }
        }        
        return calc(0).first;
    }
};
