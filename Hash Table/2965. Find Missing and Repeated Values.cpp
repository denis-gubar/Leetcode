class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<int> result{ 0, 0 };
        unordered_map<int, int> M;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                ++M[grid[i][j]];
        for (int i = 1; i <= N * N; ++i)
            if (M.find(i) == M.end())
                result[1] = i;
        for (auto [key, value] : M)
            if (value > 1)
                result[0] = key;
        return result;
    }
};
