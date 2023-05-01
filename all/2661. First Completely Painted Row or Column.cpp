class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int N = mat.size(), M = mat[0].size();
        vector<int> row(N * M + 1), col(N * M + 1);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                row[mat[i][j]] = i, col[mat[i][j]] = j;
        vector<int> R(N), C(M);
        for (int i = 0; i < N * M; ++i)
        {
            int x = row[arr[i]], y = col[arr[i]];
            if (++R[x] == M)
                return i;
            if (++C[y] == N)
                return i;
        }
        return -1;
    }
};
