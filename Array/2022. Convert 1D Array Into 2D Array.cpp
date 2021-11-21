class Solution {
public:
	vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
		if (original.size() != m * n)
			return {};
		vector<vector<int>> result(m, vector<int>(n));
		for (int i = 0, pos = 0; i < m; ++i)
			for (int j = 0; j < n; ++j, ++pos)
				result[i][j] = original[pos];
		return result;
	}
};