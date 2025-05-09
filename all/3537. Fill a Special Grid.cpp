class Solution {
public:
    int i;
    vector<vector<int>> result;
    void calc(int x, int y, int N)
    {
        if (N == 0)
            return;
        if (N == 1)
        {
            result[x][y + 1] = i++;
            result[x + 1][y + 1] = i++;
            result[x + 1][y] = i++;
            result[x][y] = i++;
            return;
        }
        int z = 1 << (N - 1);
        calc(x, y + z, N - 1);
        calc(x + z, y + z, N - 1);
        calc(x + z, y, N - 1);
        calc(x, y, N - 1);
    }
    vector<vector<int>> specialGrid(int N) {
        result = vector<vector<int>>(1 << N, vector<int>(1 << N));
        i = 0;
        calc(0, 0, N);
        return result;
    }
};
