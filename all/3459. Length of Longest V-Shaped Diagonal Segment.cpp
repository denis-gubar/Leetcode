static short F[500][500][4];
class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int const N = grid.size(), M = grid[0].size();
        int result = 0;
        memset(F, 0, sizeof(F));
        array const dx{ -1, -1, 1, 1 };
        array const dy{ -1, 1, 1, -1 };
        auto update = [](auto& x, auto value)
            {
                if (x < value)
                    x = value;
            };
        auto add = [&grid, N, M, &dx, &dy, &update](int x, int y) -> void
            {
                for (int z = 0; z < 4; ++z)
                {
                    int length = grid[x][y] != 1;
                    update(F[x][y][z], length);
                    for (int t = 1; ; ++t)
                    {
                        int const nx = x + dx[z] * t;
                        int const ny = y + dy[z] * t;
                        if (nx < 0 || nx == N || ny < 0 || ny == M)
                            break;
                        if (grid[nx][ny] == 1)
                        {
                            length = 0;
                            continue;
                        }
                        if (length == 0)
                        {
                            length = 1;
                            update(F[nx][ny][z], length);
                            continue;
                        }
                        int const px = nx - dx[z];
                        int const py = ny - dy[z];
                        if ((grid[px][py] ^ grid[nx][ny]) != 2)
                            length = 1;
                        else
                            ++length;
                        update(F[nx][ny][z], length);
                    }
                }
            };
        for (int i = 0; i < N; ++i)
            add(i, 0), add(i, M - 1);
        for (int j = 1; j < M - 1; ++j)
            add(0, j), add(N - 1, j);
        auto traverse = [&result, &grid, N, M, &dx, &dy, &update](int x, int y) -> void
            {
                update(result, 1);
                for (int z = 0; z < 4; ++z)
                {
                    for (int t = 1; ; ++t)
                    {
                        int const nx = x + dx[z] * t;
                        int const ny = y + dy[z] * t;
                        if (nx < 0 || nx == N || ny < 0 || ny == M || grid[nx][ny] == 1)
                            break;
                        int const px = nx - dx[z];
                        int const py = ny - dy[z];
                        if (((grid[px][py] & 2) ^ grid[nx][ny]) != 2)
                            break;
                        update(result, t + F[nx][ny][(z + 3) % 4]);
                        update(result, t + 1);
                    }
                }
            };
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (grid[i][j] == 1)
                    traverse(i, j);
        return result;
    }
};
