static int connectivity[26];
static int& N = connectivity[0];
static int gold[26];
static const array dx{ -1, 0, 1, 0 };
static const array dy{ 0, -1, 0, 1 };
class Solution {
public:
    int calc(int V, int total, int mask)
    {
        mask ^= 1 << V;
        total += gold[V];
        if (mask == 0)
            return total;
        int result = total;
        int nextV = mask & connectivity[V];
        while (nextV)
        {
            result = max(result, calc(__builtin_ffs(nextV) - 1, total, mask));
            nextV &= nextV - 1;
        }
        return result;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int result = 0;
        int X = grid.size(), Y = grid[0].size();
        vector<vector<int>> F(grid);
        memset(connectivity, 0, sizeof(connectivity));
        for(int i = 0; i < X; ++i)
            for(int j = 0; j < Y; ++j)
                if (grid[i][j])
                    F[i][j] = ++N, gold[N] = grid[i][j];
        for (int i = 0; i < X; ++i)
            for (int j = 0; j < Y; ++j)
                if (F[i][j])
                    for (int z = 0; z < 4; ++z)
                        if (i + dx[z] < X && i + dx[z] >= 0 &&
                            j + dy[z] < Y && j + dy[z] >= 0 &&
                            F[i + dx[z]][j + dy[z]] > 0)
                            connectivity[F[i][j]] |= 1 << F[i + dx[z]][j + dy[z]];
        for (int V = 1; V <= N; ++V)
            result = max(result, calc(V, 0, (2 << N) - 2));
        return result;
    }
};
