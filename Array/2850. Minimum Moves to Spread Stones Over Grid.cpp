class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int, int>> A, B;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
            {
                for (int x = 1; x < grid[i][j]; ++x)
                    A.emplace_back(i, j);
                if (grid[i][j] == 0)
                    B.emplace_back(i, j);
            }
        int N = B.size();
        if (N == 0)
            return 0;
        vector<int> I(N);
        iota(I.begin(), I.end(), 0);
        int result = 1000;
        do
        {
            int current = 0;
            for (int j = 0; j < N; ++j)
            {
                int i = I[j];
                current += abs(A[i].first - B[j].first) + abs(A[i].second - B[j].second);
            }
            result = min(result, current);
        } while (next_permutation(I.begin(), I.end()));
        return result;
    }
};
