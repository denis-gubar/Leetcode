static short F[200][200];
static short A[200][200];
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int result = 0;
        array const dx{ -1, 0, 1, 0 };
        array const dy{ 0, -1, 0, 1 };
        int const N = heightMap.size(), M = heightMap[0].size();
        memset(F, -1, sizeof(F));
        for (short i = 0; i < N; ++i)
            F[i][0] = heightMap[i][0], F[i][M - 1] = heightMap[i][M - 1];
        for (short j = 1; j < M - 1; ++j)
            F[0][j] = heightMap[0][j], F[N - 1][j] = heightMap[N - 1][j];
        for(short i = 1; i < N - 1; ++i)
            for(short j = 1; j < M - 1; ++j)
                if (F[i][j] == -1)
                {
                    auto check = [&heightMap, &dx, &dy, N, M](short x, short y, short level) -> bool
                        {
                            if (heightMap[x][y] >= level)
                                return false;
                            memcpy(A, F, sizeof(F));
                            queue<short> Q;
                            Q.push(x); Q.push(y); A[x][y] = -2;
                            while (!Q.empty())
                            {
                                short const x = Q.front(); Q.pop();
                                short const y = Q.front(); Q.pop();
                                for (int z = 0; z < 4; ++z)
                                {
                                    short const nx = x + dx[z];
                                    short const ny = y + dy[z];
                                    if (nx >= 0 && nx < N && ny >= 0 && ny < M)
                                    {
                                        if (A[nx][ny] >= 0)
                                        {
                                            if (A[nx][ny] < level)
                                                return false;
                                        }
                                        else if (A[nx][ny] == -1)
                                        {
                                            if (level <= heightMap[nx][ny])
                                                A[nx][ny] = heightMap[nx][ny];
                                            else
                                            {
                                                Q.push(nx); Q.push(ny); A[nx][ny] = -2;
                                            }
                                        }
                                    }
                                }
                            }
                            return true;
                        };
                    int a = heightMap[i][j], b = 20'001;
                    for (int z = 0; z < 4; ++z)
                    {
                        short const nx = i + dx[z];
                        short const ny = j + dy[z];
                        if (F[i][j] >= 0)
                            b = min<int>(b, F[i][j]);
                    }
                    while (a + 1 < b)
                    {
                        int m = (a + b) / 2;
                        if (check(i, j, m))
                            a = m;
                        else
                            b = m;
                    }
                    F[i][j] = a;
                    if (a > heightMap[i][j])
                    {
                        queue<short> Q;
                        Q.push(i); Q.push(j);
                        while (!Q.empty())
                        {
                            short const x = Q.front(); Q.pop();
                            short const y = Q.front(); Q.pop();
                            for (int z = 0; z < 4; ++z)
                            {
                                short const nx = x + dx[z];
                                short const ny = y + dy[z];
                                if (nx >= 0 && nx < N && ny >= 0 && ny < M && F[nx][ny] == -1)
                                {
                                    if (heightMap[nx][ny] >= a)
                                        F[nx][ny] = heightMap[nx][ny];
                                    else
                                    {
                                        Q.push(nx); Q.push(ny); F[nx][ny] = a;
                                    }
                                }
                            }
                        }
                    }
                }
        for (int i = 1; i < N - 1; ++i)
            for (int j = 1; j < M - 1; ++j)
                result += F[i][j] - heightMap[i][j];
        return result;
    }
};
