static array const dx{ -2, -2, -1, -1, 1, 1, 2, 2 };
static array const dy{ -1, 1, -2, 2, -2, 2, -1, 1 };
class Solution {
public:
    vector<vector<int>> result;
    int N, M;
    bool calc(int mask, int x, int y)
    {
        if (mask == 0) return true;
        for (int z = 0; z < 8; ++z)
        {
            int const nx = x + dx[z];
            int const ny = y + dy[z];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && (mask & (1 << (nx * M + ny))) > 0)
            {
                result[nx][ny] = result[x][y] + 1;
                if (calc(mask ^ (1 << (nx * M + ny)), nx, ny))
                    return true;
            }
        }
        return false;
    }
    vector<vector<int>> tourOfKnight(int N, int M, int r, int c) {
        result = vector<vector<int>>(N, vector<int>(M, -1));
        this->N = N, this->M = M;
        result[r][c] = 0;
        calc(((1 << (N * M)) - 1) ^ (1 << (r * M + c)), r, c);
        return result;
    }
};
