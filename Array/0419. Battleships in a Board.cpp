class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int result = 0;
        int N = board.size(), M = board[0].size();
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                result += board[i][j] == 'X' && (i == 0 || board[i - 1][j] == '.') && (j == 0 || board[i][j - 1] == '.');
        return result;
    }
};
