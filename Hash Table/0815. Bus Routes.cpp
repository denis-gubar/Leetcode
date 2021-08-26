class Solution {
public:
    int numBusesToDestination( vector<vector<int>>& routes, int S, int T ) {
        if ( S == T )
            return 0;
        vector<set<int>> setRoutes;
        for (const auto& route : routes)
            setRoutes.push_back( set<int>( route.begin(), route.end() ) );
        queue<int> q;
        vector<int> isVisited( setRoutes.size() );
        for (int i = 0; i < setRoutes.size(); ++i)
            if (setRoutes[i].find( S ) != setRoutes[i].end())
            {
                q.push( i ), q.push( 1 );
                isVisited[i] = 1;
            }
        while (!q.empty())
        {
            int v = q.front(); q.pop();
            int t = q.front(); q.pop();
            if (setRoutes[v].find( T ) != setRoutes[v].end())
                return t;
            for (int i = 0; i < setRoutes.size(); ++i)
                if ( !isVisited[i])
                {                    
                    for(int u: setRoutes[i])
                        if (setRoutes[v].find( u ) != setRoutes[v].end())
                        {
                            q.push( i ), q.push( t + 1 );
                            isVisited[i] = 1;
                            break;
                        }
                    
                }
        }
        return -1;
    }
};