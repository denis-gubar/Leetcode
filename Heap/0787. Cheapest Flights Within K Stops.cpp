class Solution {
public:
    int findCheapestPrice( int n, vector<vector<int>>& flights, int src, int dst, int K ) {
        int result = -1;
        vector<vector<int>> M( n, vector<int>( n, 100000000 ) );
        for (const auto& f : flights)
            M[f[0]][f[1]] = f[2];
        for (int i = 0; i < n; ++i)
            M[i][i] = 0;
        queue<int> Q;        
        vector<int> isVisited(n, 100000000);
        isVisited[src] = 0;
        for(int v = 0; v < n; ++v)
            if (src != v && M[src][v] < 100000000)
            {
                isVisited[v] = M[src][v];
                Q.push( v );
                Q.push( 0 );
            }
        while (!Q.empty())
        {
            int v = Q.front(); Q.pop();
            int stops = Q.front(); Q.pop();
            for (int u = 0; u < n; ++u)
                if (v != u)
                {
                    if (M[src][u] > M[src][v] + M[v][u])
                        M[src][u] = M[src][v] + M[v][u];
                    if (stops < K && isVisited[u] > M[src][u] )
                    {
                        isVisited[u] = M[src][u];
                        Q.push( u );
                        Q.push( stops + 1 );
                    }
                }
        }
        if (isVisited[dst] < 100000000)
            result = isVisited[dst];
        return result;
    }
};