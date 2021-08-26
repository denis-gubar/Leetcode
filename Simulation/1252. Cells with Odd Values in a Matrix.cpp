class Solution {
public:
	int oddCells(int n, int m, vector<vector<int>>& indices) {
		vector<vector<int>> M(n, vector<int>(m));
		for (vector<int> const& ind : indices)
		{
			int const& a = ind[0];
			int const& b = ind[1];
			for (int i = 0; i < n; ++i)
				++M[i][b];
			for (int i = 0; i < m; ++i)
				++M[a][i];
		}
		int result = 0;
        int x = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				result += M[i][j] % 2, x += 1;
		return result;
	}
};