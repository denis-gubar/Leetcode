class Solution {
public:
    map<pair<int, int>, pair<int, int>> M;
    vector<vector<int>> connectivity;
    pair<int, int> calc( int v, int u )
    {
        if (M.find( { v, u } ) != M.end())
            return M[{v, u}];
        pair<int, int> result{ 1, 1 };
        for (int x : connectivity[u])
            if (x != v)
            {
                pair<int, int> current = calc( u, x );
                result.second += current.second;
                result.first += current.first + current.second;
            }
        return M[{v, u}] = result;
    }
    vector<int> sumOfDistancesInTree( int N, vector<vector<int>>& edges ) {
        vector<int> result( N );
        connectivity = vector<vector<int>>( N );
        M.clear();
        for (int i = 0; i + 1 < N; ++i)
        {
            int v = edges[i][0], u = edges[i][1];
            connectivity[v].push_back( u );
            connectivity[u].push_back( v );
        }
        for (int v = 0; v < N; ++v)
            for (int u : connectivity[v])
                result[v] += calc( v, u ).first;
        return result;
    }
};