class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int K) {
        long long result = 0;
        int const N = grid.size(), M = grid[0].size();
        vector<int> A, B;
        A.reserve(N * M);
        B.reserve(M);
        for (int i = 0; i < N; ++i)
        {
            B = grid[i];
            sort(B.begin(), B.end());
            for (int j = 0; j < limits[i]; ++j)
            {
                A.push_back(B.back());
                B.pop_back();
            }
        }
        sort(A.begin(), A.end());
        for (int j = 0; j < K; ++j)
        {
            result += A.back();
            A.pop_back();
        }
        return result;
    }
};
