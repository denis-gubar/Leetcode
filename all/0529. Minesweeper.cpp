class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int const N = board.size(), M = board[0].size();
        int const& x = click[0];
        int const& y = click[1];
        if (board[x][y] == 'M')
            board[x][y] = 'X';
        else
        {
            auto calc = [&board, N, M](int x, int y) -> int
                {
                    int result = 0;
                    for (int nx = max(0, x - 1); nx <= min(N - 1, x + 1); ++nx)
                        for (int ny = max(0, y - 1); ny <= min(M - 1, y + 1); ++ny)
                            result += board[nx][ny] == 'M';
                    return result;
                };
            queue<int> Q;
            Q.push(x); Q.push(y);
            board[x][y] = 'B';
            while (!Q.empty())
            {
                int x = Q.front(); Q.pop();
                int y = Q.front(); Q.pop();
                int r = calc(x, y);
                if (r > 0)
                {
                    board[x][y] = r + '0';
                    continue;
                }
                for (int nx = max(0, x - 1); nx <= min(N - 1, x + 1); ++nx)
                    for (int ny = max(0, y - 1); ny <= min(M - 1, y + 1); ++ny)
                        if (board[nx][ny] == 'E')
                        {
                            Q.push(nx); Q.push(ny);
                            board[nx][ny] = 'B';
                        }
            }
        }
        return board;
    }
};
