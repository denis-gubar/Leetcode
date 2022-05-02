class Solution {
public:
    struct Data
    {
        int x;
        int y;
        int value;
    };
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int M = mat1.size(), K = mat2.size(), N = mat2[0].size();
        vector<Data> A, B;
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < K; ++j)
                if (mat1[i][j])
                    A.push_back({ i, j, mat1[i][j] });
        for (int i = 0; i < K; ++i)
            for (int j = 0; j < N; ++j)
                if (mat2[i][j])
                    B.push_back({ i, j, mat2[i][j] });
        vector<vector<int>> result(M, vector<int>(N));
        for (Data L : A)
            for (Data R : B)
                if (L.y == R.x)
                    result[L.x][R.y] += L.value * R.value;
        return result;
    }
};
