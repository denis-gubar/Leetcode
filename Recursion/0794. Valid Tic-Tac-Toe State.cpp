class Solution {
public:
    vector<int> calc( const vector<string>& board )
    {
        vector<int> wins;
        for (int i = 0; i < 3; ++i)
        {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2])
                wins.push_back( board[i][0] );
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[0][i] == board[2][i])
                wins.push_back( board[0][i] );
        }
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2])
            wins.push_back( board[0][0] );
        if (board[2][0] != ' ' && board[2][0] == board[1][1] && board[1][1] == board[0][2])
            wins.push_back( board[2][0] );
        return wins;
    }
    bool validTicTacToe( vector<string>& board ) {
        int x = 0, o = 0;
        for (const auto & b : board)
            for (char c : b)
            {
                x += c == 'X';
                o += c == 'O';
            }
        if (o > x || x - o > 1)
            return false;
        vector<int> wins = calc( board );
        if (wins.empty())
            return true;
        if ( x == o && wins[0] == 'X' )
            return false;
        if ( x > o && wins[0] == 'O' )
            return false;
        bool result = false;
        for(int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
            {
                if (board[i][j] == wins[0])
                {
                    board[i][j] = ' ';
                    vector<int> w = calc( board );
                    result |= w.empty();
                    board[i][j] = wins[0];
                }
            }
        return result;
    }
};