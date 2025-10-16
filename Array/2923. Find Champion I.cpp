class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int N = grid.size();
        for (int i = 0; i < N; ++i)
        {
            int count = 0;
            for (int j = 0; j < N; ++j)
                count += grid[i][j];
            if (count == N - 1)
                return i;
        }
        return -1;
    }
};
