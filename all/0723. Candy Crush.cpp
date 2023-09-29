class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int N = board.size(), M = board[0].size();
        bool flag = true;
        vector<int> topRows(M);
        auto check = [&board, N, M](int x, int y) -> bool
            {
                int const& value = board[x][y];
                if (value == 0)
                    return false;
                int dx = 2, dy = 2;
                for (int nx = x + 1; nx < min(x + 3, N); ++nx)
                    if (board[nx][y] != value)
                        break;
                    else
                        --dx;
                for (int nx = x - 1; nx >= 0; --nx)
                    if (board[nx][y] != value)
                        break;
                    else
                        --dx;
                for (int ny = y + 1; ny < min(y + 3, M); ++ny)
                    if (board[x][ny] != value)
                        break;
                    else
                        --dy;
                for (int ny = y - 1; ny >= 0; --ny)
                    if (board[x][ny] != value)
                        break;
                    else
                        --dy;
                return dx <= 0 || dy <= 0;
            };
        while (flag)
        {
            flag = false;
            vector<vector<int>> A(M);
            for (int j = 0; j < M; ++j)
                for (int i = topRows[j]; i < N; ++i)
                    if (check(i, j))
                        A[j].emplace_back(i);
            for (int j = 0; j < M; ++j)
                if (!A[j].empty())
                {
                    int pos = A[j].back();
                    int k = pos;
                    flag = true;
                    while (board[pos][j] != 0)
                    {
                        while (k >= 0 && !A[j].empty() && k == A[j].back())
                            --k, A[j].pop_back();
                        if (k >= 0)
                            board[pos][j] = board[k][j], --k, --pos;
                        else
                        {
                            while (pos >= 0 && board[pos][j] != 0)
                                board[pos][j] = 0, --pos;
                            break;
                        }
                    }
                }
        }
        return board;
    }
};
