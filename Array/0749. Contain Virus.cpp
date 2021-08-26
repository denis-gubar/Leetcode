class Solution {
public:
    int containVirus( vector<vector<int>> grid ) {
        int result = 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> dx = { -1, 0, 1, 0 };
        vector<int> dy = { 0, -1, 0, 1 };
        vector<vector<int>> W( m, vector<int>( n ) );
        for (int j = 0; j < n; ++j)
            W[0][j] |= (1 << 0);
        for (int i = 0; i < m; ++i)
            W[i][0] |= (1 << 1);
        for (int j = 0; j < n; ++j)
            W[m - 1][j] |= (1 << 2);
        for (int i = 0; i < m; ++i)
            W[i][n - 1] |= (1 << 3);
        while (true)
        {
            int k = 0;
            vector<vector<int>> M( m, vector<int>( n ) );
            vector<pair<int, int>> regions( 1, make_pair( -1, -1 ) );
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j)
                    if (grid[i][j] == 1 && M[i][j] == 0)
                    {
                        ++k;
                        M[i][j] = k;
                        regions.push_back( make_pair( i, j ) );
                        queue<int> q;
                        q.push( i ); q.push( j );
                        while (!q.empty())
                        {
                            int x = q.front(); q.pop();
                            int y = q.front(); q.pop();
                            for (int z = 0; z < 4; ++z)
                            {
                                int nx = x + dx[z];
                                int ny = y + dy[z];
                                if (((W[x][y] & (1 << z)) == 0) && M[nx][ny] != k && grid[nx][ny] == 1)
                                {
                                    M[nx][ny] = k;
                                    q.push( nx ); q.push( ny );
                                }
                            }
                        }
                    }
            vector<set<pair<int, int>>> affected( regions.size() );
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j)
                    if (M[i][j] > 0)
                    {
                        int x = i;
                        int y = j;
                        for (int z = 0; z < 4; ++z)
                        {
                            int nx = x + dx[z];
                            int ny = y + dy[z];
                            if (((W[x][y] & (1 << z)) == 0) && grid[nx][ny] == 0)
                                affected[M[i][j]].insert( make_pair( nx, ny ) );
                        }
                    }
            int most_dangerous = 0;
            for (int k = 1; k < regions.size(); ++k)
                if (affected[k].size() > affected[most_dangerous].size())
                    most_dangerous = k;
            if (affected[most_dangerous].size() == 0)
                return result;
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j)
                    if (M[i][j] == most_dangerous)
                    {
                        int x = i;
                        int y = j;
                        for (int z = 0; z < 4; ++z)
                        {
                            int nx = x + dx[z];
                            int ny = y + dy[z];
                            if (((W[x][y] & (1 << z)) == 0) && grid[nx][ny] == 0)
                            {
                                W[x][y] |= (1 << z);
                                ++result;
                            }
                        }
                    }
            bool flag = false;
            vector<vector<int>> new_grid( grid );
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j)
                    if (new_grid[i][j] == 1)
                    {
                        int x = i;
                        int y = j;
                        for (int z = 0; z < 4; ++z)
                        {
                            int nx = x + dx[z];
                            int ny = y + dy[z];
                            if (((W[x][y] & (1 << z)) == 0) && new_grid[nx][ny] == 0)
                                grid[nx][ny] = 1;
                        }
                    }
                    else
                        flag = true;
            if (!flag)
                return result;
        }
        return -1;
    }
};