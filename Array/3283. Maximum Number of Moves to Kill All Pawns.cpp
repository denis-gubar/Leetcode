static char DD[50][50][50][50];
static char D[50][50];
static bool isInit = false;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        array dx = { -2, -2, -1, -1, 1, 1, 2, 2 };
        array dy = { -1, 1, -2, 2, -2, 2, -1, 1 };
        memset(DD, 100, sizeof(DD));
        memset(D, 100, sizeof(D));
        for(char i = 0; i < 50; ++i)
            for(char j = 0; j < 50; ++j)
                if (i < 2 || j < 2 || i > 47 || j > 47 || i == 2 && j == 2)
                {
                    queue<char> Q;
                    Q.push(i); Q.push(j);
                    DD[i][j][i][j] = 0;
                    while (!Q.empty())
                    {
                        char const x = Q.front(); Q.pop();
                        char const y = Q.front(); Q.pop();
                        for (char z = 0; z < 8; ++z)
                        {
                            char const nx = x + dx[z];
                            char const ny = y + dy[z];
                            if (nx >= 0 && nx < 50 && ny >= 0 && ny < 50 && DD[i][j][x][y] + 1 < DD[i][j][nx][ny])
                            {
                                DD[i][j][nx][ny] = DD[i][j][x][y] + 1;
                                Q.push(nx); Q.push(ny);
                            }
                        }
                    }
                }
        for (int i = 2; i < 50; ++i)
            for (int j = 2; j < 50; ++j)
                D[i - 2][j - 2] = DD[2][2][i][j];
    }
}
static int distance(int x, int y, int nx, int ny)
{
    if (x < 2 || y < 2 || x > 47 || y > 47)
        return DD[x][y][nx][ny];
    if (nx < 2 || ny < 2 || nx > 47 || ny > 47)
        return DD[nx][ny][x][y];
    return D[abs(nx - x)][abs(ny - y)];
}
static int F[16][1 << 15];
class Solution {
public:
    int N;
    vector<vector<int>> positions;
    int dist(int a, int b)
    {
        return distance(positions[a][0], positions[a][1], positions[b][0], positions[b][1]);
    }
    int calc(int x, int mask, bool isAlice = true)
    {
        if (mask == 0)
            return 0;
        int& result = F[x][mask];
        if (result < 0)
        {
            if (isAlice)
            {
                int current = 0;
                for (int k = 0; k < N; ++k)
                    if (mask & (1 << k))
                        current = max(current, calc(k, mask ^ (1 << k), !isAlice) + dist(x, k));
                result = current;
            }
            else
            {
                int current = 1 << 20;
                for (int k = 0; k < N; ++k)
                    if (mask & (1 << k))
                        current = min(current, calc(k, mask ^ (1 << k), !isAlice) + dist(x, k));
                result = current;
            }
        }
        return result;
    }
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        init();
        N = positions.size();
        this->positions = positions;
        this->positions.push_back(vector<int>{ kx, ky });
        memset(F, -1, sizeof(F));
        return calc(N, (1 << N) - 1);
    }
};
