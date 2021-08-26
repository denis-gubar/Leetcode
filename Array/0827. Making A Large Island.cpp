class Solution {
public:
    int largestIsland( vector<vector<int>>& grid ) {
        int n = grid.size(), m = grid[0].size();
        vector<int> sizes( 1 );
        vector<vector<int>> visited(n, vector<int>( m ));
        int group = 0;
        vector<int> dx{ 0, 1, 0, -1 };
        vector<int> dy{ 1, 0, -1, 0 };
        for(int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (!visited[i][j] && grid[i][j])
                {
                    ++group;
                    visited[i][j] = group;
                    sizes.push_back( 1 );
                    queue<int> Q;
                    Q.push( i ); Q.push( j );
                    while (!Q.empty())
                    {
                        int x = Q.front(); Q.pop();
                        int y = Q.front(); Q.pop();
                        for (int z = 0; z < 4; ++z)
                        {
                            int nx = x + dx[z], ny = y + dy[z];
                            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny])
                            {
                                visited[nx][ny] = group;
                                Q.push( nx ); Q.push( ny );
                                ++sizes.back();
                            }
                        }
                    }
                }
        int result = *max_element( sizes.begin(), sizes.end() );
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (!visited[i][j])
                {
                    set<int> S;
                    for (int z = 0; z < 4; ++z)
                    {
                        int nx = i + dx[z], ny = j + dy[z];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                            S.insert( visited[nx][ny] );
                    }
                    int current = 1;
                    for (int s : S)
                        current += sizes[s];
                    result = max( result, current );
                }
        return result;
    }
};