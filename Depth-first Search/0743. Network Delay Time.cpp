class Solution {
public:
    int networkDelayTime( vector<vector<int>>& times, int N, int K ) {
        int result = 0;
        vector<int> d( N + 1, INT_MAX ), p( N + 1);
        vector<vector<pair<int, int>>> g( N + 1 );
        for (auto x : times)
            g[x[0]].push_back( make_pair( x[1], x[2] ) );
        d[K] = 0;
        vector<int> visited( N + 1 );
        for (int i = 0; i < N; ++i)
        {
            int v = -1;
            for (int j = 1; j <= N; ++j)
                if (!visited[j] && (v == -1 || d[j] < d[v]))
                    v = j;
            if (d[v] == INT_MAX)
                return -1;
            visited[v] = 1;

            for (auto j : g[v])
            {
                int to = j.first;
                int length = j.second;
                if (d[v] + length < d[to])
                    d[to] = d[v] + length;
            }
        }
        return *max_element(d.begin() + 1, d.end());
    }
};