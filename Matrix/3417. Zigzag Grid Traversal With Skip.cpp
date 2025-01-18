class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> result;
        int const N = grid.size(), M = grid[0].size();
        for (int i = 0, flag = true; i < N; i += 2)
        {
            for (int j = 0; j < M; ++j)
                if (flag)
                    result.push_back(grid[i][j]), flag = false;
                else
                    flag = true;
            if (i + 1 < N)
                for (int j = M - 1; j >= 0; --j)
                    if (flag)
                        result.push_back(grid[i + 1][j]), flag = false;
                    else
                        flag = true;
        }
        return result;
    }
};
