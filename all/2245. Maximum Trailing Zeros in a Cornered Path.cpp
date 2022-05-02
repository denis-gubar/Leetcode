class Solution {
public:
    int calc(int x, int k)
    {
        int result = 0;
        while (x % k == 0)
        {
            x /= k;
            ++result;
        }
        return result;
    }
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int result = 0;
        int N = grid.size(), M = grid[0].size();
        vector<vector<int>> C2(grid), C5(grid);
        for(int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
            {
				C2[i][j] = calc(grid[i][j], 2);
				C5[i][j] = calc(grid[i][j], 5);
            }
        vector<vector<int>> H2(N, vector<int>(M + 1)), H5(N, vector<int>(M + 1));
        vector<vector<int>> V2(M, vector<int>(N + 1)), V5(M, vector<int>(N + 1));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
            {
                H2[i][j + 1] = H2[i][j] + C2[i][j];
                H5[i][j + 1] = H5[i][j] + C5[i][j];
            }
        for(int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j)
            {
				V2[i][j + 1] = V2[i][j] + C2[j][i];
				V5[i][j + 1] = V5[i][j] + C5[j][i];
            }
        for (int i = 0; i < M; ++i)
        {
            int d2 = 0, d5 = 0;
            for (int j = 0; j < N; ++j)
            {
                d2 += C2[j][i];
                d5 += C5[j][i];
                int left2 = H2[j][i], left5 = H5[j][i];
                int right2 = H2[j][M] - H2[j][i + 1], right5 = H5[j][M] - H5[j][i + 1];
                int current = max(min(left2 + d2, left5 + d5), min(right2 + d2, right5 + d5));
                result = max(result, current);
            }
            d2 = 0, d5 = 0;
            for (int j = N - 1; j >= 0; --j)
            {
				d2 += C2[j][i];
				d5 += C5[j][i];
				int left2 = H2[j][i], left5 = H5[j][i];
				int right2 = H2[j][M] - H2[j][i + 1], right5 = H5[j][M] - H5[j][i + 1];
				int current = max(min(left2 + d2, left5 + d5), min(right2 + d2, right5 + d5));
				result = max(result, current);
            }
        }
        for (int i = 0; i < N; ++i)
        {
            int d2 = 0, d5 = 0;
            for (int j = 0; j < M; ++j)
            {
                d2 += C2[i][j];
                d5 += C5[i][j];
                int top2 = V2[j][i], top5 = V5[j][i];
                int bottom2 = V2[j][N] - V2[j][i + 1], bottom5 = V5[j][N] - V5[j][i + 1];
                int current = max(min(top2 + d2, top5 + d5), min(bottom2 + d2, bottom5 + d5));
                result = max(result, current);
            }
			d2 = 0, d5 = 0;
			for (int j = M - 1; j >= 0; --j)
			{
				d2 += C2[i][j];
				d5 += C5[i][j];
				int top2 = V2[j][i], top5 = V5[j][i];
				int bottom2 = V2[j][N] - V2[j][i + 1], bottom5 = V5[j][N] - V5[j][i + 1];
				int current = max(min(top2 + d2, top5 + d5), min(bottom2 + d2, bottom5 + d5));
				result = max(result, current);
			}
        }
        return result;
    }
};
