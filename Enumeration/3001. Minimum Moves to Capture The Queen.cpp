class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        int result = 2;
        array rx = { -1, 0, 1, 0 };
        array ry = { 0, -1, 0, 1 };
        array bx = { -1, -1, 1, 1 };
        array by = { -1, 1, -1, 1 };
        vector<vector<int>> M(9, vector<int>(9));
        M[a][b] = 1;
        M[c][d] = 2;
        M[e][f] = 3;
        for (int z = 0; z < 4; ++z)
            for (int i = 1; i < 8; ++i)
            {
                int nx = a + rx[z] * i;
                int ny = b + ry[z] * i;
                if (nx < 1 || nx > 8 || ny < 1 || ny > 8)
                    break;
                if (M[nx][ny] == 2)
                    break;
                if (M[nx][ny] == 3)
                    return 1;
            }
        for (int z = 0; z < 4; ++z)
            for (int i = 1; i < 8; ++i)
            {
                int nx = c + bx[z] * i;
                int ny = d + by[z] * i;
                if (nx < 1 || nx > 8 || ny < 1 || ny > 8)
                    break;
                if (M[nx][ny] == 1)
                    break;
                if (M[nx][ny] == 3)
                    return 1;
            }
        return result;
    }
};
