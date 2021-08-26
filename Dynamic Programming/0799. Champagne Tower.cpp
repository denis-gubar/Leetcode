class Solution {
public:
	double champagneTower(int poured, int query_row, int query_glass) {
		vector<vector<double>> F(query_row + 1, vector<double>(query_row + 1));
		F[0][0] = poured;
		for(int i = 0; i < query_row; ++i)
			for(int j = 0; j <= i; ++j)
				if (F[i][j] > 1.0)
				{
					double extra = F[i][j] - 1.0;
					F[i][j] = 1.0;
					F[i + 1][j] += 0.5 * extra;
					F[i + 1][j + 1] += 0.5 * extra;
				}
		return min(1.0, F[query_row][query_glass]);
	}
};