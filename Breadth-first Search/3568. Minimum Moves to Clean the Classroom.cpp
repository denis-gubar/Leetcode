static short F[20][20][51][1 << 10];
class Solution {
public:
    struct Data
    {
        char x;
        char y;
        char e;
        short l;
    };
    int minMoves(vector<string>& classroom, int energy) {
        int const N = classroom.size(), M = classroom[0].size();
        int L = 0;
        char x = 0, y = 0;
        vector<vector<short>> P(N, vector<short>(M));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
            {
                if (classroom[i][j] == 'L')
                {
                    P[i][j] = 1 << L;
                    ++L;
                }
                if (classroom[i][j] == 'S')
                    x = i, y = j;
            }
        memset(F, 10, sizeof(F));
        int const INF = F[0][0][0][0];
        F[x][y][energy][0] = 0;
        int result = INF;
        array const dx{ -1, 0, 1, 0 };
        array const dy{ 0, -1, 0, 1 };
        queue<Data> Q;
        Q.push({ x, y, static_cast<char>(energy), 0});
        while (!Q.empty())
        {
            Data q = Q.front(); Q.pop();
            char const& x = q.x;
            char const& y = q.y;
            char const& e = q.e;
            short const& l = q.l;
            if (l == (1 << L) - 1)
            {
                result = min<int>(result, F[x][y][e][l]);
                break;
            }
            if (e == 0)
                continue;
            for (int z = 0; z < 4; ++z)
            {
                char nx = x + dx[z];
                char ny = y + dy[z];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M && classroom[nx][ny] != 'X')
                {
                    char ne = (classroom[nx][ny] == 'R') ? energy : (e - 1);
                    short nl = l | P[nx][ny];
                    if (F[nx][ny][ne][nl] > F[x][y][e][l] + 1)
                    {
                        F[nx][ny][ne][nl] = F[x][y][e][l] + 1;
                        Q.push({ nx, ny, ne, nl });
                    }
                }
            }
        }
        if (result == INF)
            return -1;
        return result;
    }
};
