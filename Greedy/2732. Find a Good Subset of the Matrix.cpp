class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size();
        vector<int> result;
        vector<int> A(1 << M);
        vector<vector<int>> I(1 << M);
        for (int i = 0; i < N; ++i)
        {
            int mask = 0;
            for (int j = 0; j < M; ++j)
                mask |= grid[i][j] << j;
            ++A[mask];
            I[mask].push_back(i);
        }
        if (A[0] > 0)
            result = I[0];
        for(int i = 0; i < (1 << M); ++i)
            if (A[i] > 0)
                for(int j = i + 1; j < (1 << M); ++j)
                    if (A[j] > 0 && (i & j) == 0)
                    {
                        if (I[i][0] > I[j][0])
                            return { I[j][0], I[i][0] };
                        return { I[i][0], I[j][0] };
                    }
        return result;
    }
};
