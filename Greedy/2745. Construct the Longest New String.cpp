class Solution {
public:
    int longestString(int X, int Y, int Z) {
        int F[51][51][51][4];
        //AA - 1
        //B  - 2
        //BB - 3
        int result = 0;
        memset(F, 0, sizeof(F));
        queue<int> Q;
        F[0][0][0][0] = 1;
        Q.push(0); Q.push(0); Q.push(0); Q.push(0);
        while (!Q.empty())
        {
            int x = Q.front(); Q.pop();
            int y = Q.front(); Q.pop();
            int z = Q.front(); Q.pop();
            int s = Q.front(); Q.pop();
            if (s == 0)
            {
                if (x < X && !F[x + 1][y][z][1])
                {
                    F[x + 1][y][z][1] = 1;
                    Q.push(x + 1); Q.push(y); Q.push(z); Q.push(1);
                }
                if (y < Y && !F[x][y + 1][z][3])
                {
                    F[x][y + 1][z][3] = 1;
                    Q.push(x); Q.push(y + 1); Q.push(z); Q.push(3);
                }
                if (z < Z && !F[x][y][z + 1][2])
                {
                    F[x][y][z + 1][2] = 1;
                    Q.push(x); Q.push(y); Q.push(z + 1); Q.push(2);
                }
            }
            else if (s == 1)
            {
                if (y < Y && !F[x][y + 1][z][3])
                {
                    F[x][y + 1][z][3] = 1;
                    Q.push(x); Q.push(y + 1); Q.push(z); Q.push(3);
                }
            }
            else if (s == 2)
            {
                if (x < X && !F[x + 1][y][z][1])
                {
                    F[x + 1][y][z][1] = 1;
                    Q.push(x + 1); Q.push(y); Q.push(z); Q.push(1);
                }
                if (z < Z && !F[x][y][z + 1][2])
                {
                    F[x][y][z + 1][2] = 1;
                    Q.push(x); Q.push(y); Q.push(z + 1); Q.push(2);
                }
            }
            else
            {
                if (x < X && !F[x + 1][y][z][1])
                {
                    F[x + 1][y][z][1] = 1;
                    Q.push(x + 1); Q.push(y); Q.push(z); Q.push(1);
                }
                if (z < Z && !F[x][y][z + 1][2])
                {
                    F[x][y][z + 1][2] = 1;
                    Q.push(x); Q.push(y); Q.push(z + 1); Q.push(2);
                }
            }
        }
        for (int x = 0; x <= X; ++x)
            for (int y = 0; y <= Y; ++y)
                for (int z = 0; z <= Z; ++z)
                    for (int s = 0; s < 4; ++s)
                        if (F[x][y][z][s])
                            result = max(result, x + y + z);
        return 2 * result;
    }
};
