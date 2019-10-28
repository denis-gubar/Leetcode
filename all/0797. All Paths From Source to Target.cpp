class Solution {
public:
    vector<vector<int>> result;
    int N;
    void calc( const vector<vector<int>>& graph, const vector<int>& path )
    {
        int v = path.back();
        if (v == N - 1)
        {
            result.push_back( path );
            return;
        }
        for(int u: graph[v])
            if (find( path.begin(), path.end(), u ) == path.end())
            {
                vector<int> newPath( path );
                newPath.push_back( u );
                calc( graph, newPath );
            }
    }
    vector<vector<int>> allPathsSourceTarget( vector<vector<int>>& graph ) {
        result = vector<vector<int>>();
        N = graph.size();
        calc( graph, vector<int>(1) );
        return result;
    }
};