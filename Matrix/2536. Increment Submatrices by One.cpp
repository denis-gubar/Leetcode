class Solution {
public:
    vector<vector<int>> rangeAddQueries(int N, vector<vector<int>>& queries) {
        vector<vector<int>> result(N, vector<int>(N));
        vector<vector<int>> A(N, vector<int>(N + 1));
        for (int q = 0; q < queries.size(); ++q)
        {
            int const& row1 = queries[q][0];
            int const& col1 = queries[q][1];
            int const& row2 = queries[q][2];
            int const& col2 = queries[q][3];
            for (int x = row1; x <= row2; ++x)
                ++A[x][col1], --A[x][col2 + 1];
        }
        for (int x = 0; x < N; ++x)
        {
            int balance = 0;
            for (int y = 0; y < N; ++y)
            {
                balance += A[x][y];
                result[x][y] = balance;
            }
        }
        return result;
    }
};
