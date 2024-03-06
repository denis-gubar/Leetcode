class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int N = grid.size();
        int result = N * N;
        set<pair<int, int>> S;
        int i = 0;
        for (int a = 0, b = N - 1; a <= b; ++i, ++a, --b)
        {
            S.emplace(i, a);
            S.emplace(i, b);
        }
        while (i < N)
        {
            S.emplace(i, N / 2);
            ++i;
        }
        vector<vector<int>> A(3, vector<int>(3));
        for(int a = 0; a < 3; ++a)
            for (int b = 0; b < 3; ++b)
                for (int i = 0; i < N; ++i)
                    for (int j = 0; j < N; ++j)
                        if (S.find({ i, j }) != S.end())
                            A[a][b] += grid[i][j] != a;
                        else
                            A[a][b] += grid[i][j] != b;
        for (int a = 0; a < 3; ++a)
            for (int b = 0; b < 3; ++b)
                if (a != b)
                    result = min(result, A[a][b]);
        return result;
    }
};
