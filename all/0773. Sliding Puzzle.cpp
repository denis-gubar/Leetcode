class Solution {
public:
    int calcState( const vector<vector<int>>& board )
    {
        int result = 0, k = 1;
        for(int i = 0; i < 2; ++i)
            for (int j = 0; j < 3; ++j, k *= 6)
                result += board[i][j] * k;
        return result;
    }
    int slidingPuzzle( vector<vector<int>>& board ) {
        int goodState = calcState( { {1,2,3}, {4,5,0} } ), badState = calcState( { { 1,2,3 },{ 5,4,0 } } );
        vector<int> dx = { 0, 1, 0, -1 };
        vector<int> dy = { 1, 0, -1, 0 };
        queue<vector<vector<int>>> Q;
        queue<int> q;
        Q.push( board );
        q.push( 0 );
        vector<char> isVisited( 50000 );
        isVisited[calcState( board )] = 1;
        while (!Q.empty())
        {
            vector<vector<int>> position = Q.front(); Q.pop();
            if (calcState( position ) == badState)
                return -1;
            int step = q.front(); q.pop();
            if (calcState( position ) == goodState)
                return step;
            int x = 0, y = 0;
            for (int i = 0; i < 2; ++i)
                for (int j = 0; j < 3; ++j)
                    if (!position[i][j])
                    {
                        x = i; y = j;
                    }
            for (int z = 0; z < 4; ++z)
            {
                int nx = x + dx[z], ny = y + dy[z];
                if (nx >= 0 && nx < 2 && ny >= 0 && ny < 3)
                {
                    vector<vector<int>> newPosition( position );
                    swap( newPosition[x][y], newPosition[nx][ny] );
                    if (!isVisited[calcState( newPosition )])
                    {
                        isVisited[calcState( newPosition )] = 1;
                        Q.push( newPosition );
                        q.push( step + 1 );
                    }
                }
            }

        }
        return -2;
    }
};