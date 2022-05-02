class Solution {
public:
    vector<bitset<1000>> connectivity, F;
    vector<bool> visited;
    int N;
    void calc(int V)
    {
        if (!visited[V])
        {
            for(int from = 0; from < N; ++from)
                if (connectivity[from][V])
                {
                    calc(from);
                    F[V] |= F[from];
                    F[V][from] = true;
                }
            visited[V] = true;
        }
    }
    vector<vector<int>> getAncestors(int N, vector<vector<int>>& edges) {
        this->N = N;
        vector<vector<int>> result(N);
        connectivity = vector<bitset<1000>>(N);
        F = connectivity;
        visited = vector<bool>(N);
        for (vector<int> const& e : edges)
        {
            int const& from = e[0];
            int const& to = e[1];
            connectivity[from][to] = true;
        }
        for (int i = 0; i < N; ++i)
            calc(i);
        for (int to = 0; to < N; ++to)
            for (int from = 0; from < N; ++from)
                if (F[to][from])
                    result[to].push_back(from);
        return result;
    }
};
