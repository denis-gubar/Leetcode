class Solution {
public:
    bool isBipartite( vector<vector<int>>& graph ) {
        int N = graph.size();
        vector<int> colors( N );
        for(int i = 0; i < N; ++i)
            if( !colors[i])
            {
                colors[i] = 1;
                queue<int> Q;
                Q.push( i );
                Q.push( 2 );
                while (!Q.empty())
                {
                    int v = Q.front(); Q.pop();
                    int c = Q.front(); Q.pop();
                    for (int u : graph[v])
                    {
                        if (!colors[u])
                        {
                            colors[u] = c;
                            Q.push( u );
                            Q.push( 3 - c );
                        }
                        else if (colors[u] != c)
                            return false;
                    }
                }
            }
        return true;
    }
};