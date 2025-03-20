static int F[301][301];
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int const N = matrix.size(), M = matrix[0].size();
        memset(F, 0, sizeof(F));
        int result = 0;
        auto update = [&result](int& x, int value)
            {
                if (x < value)
                {
                    x = value;
                    result = max(result, value * value);
                }
            };
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (matrix[i][j] == '1')
                    update(F[i + 1][j + 1], min({ F[i][j], F[i + 1][j], F[i][j + 1] }) + 1);
        return result;
    }
};
