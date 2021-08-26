class Solution {
public:
	vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
		vector<vector<int>> result(R * C, vector<int>(2));
		for (int r = 0; r < R; ++r)
			for (int c = 0; c < C; ++c)
				result[r * C + c][0] = r, result[r * C + c][1] = c;
		sort(result.begin(), result.end(),
			[r0, c0](vector<int> const& a, vector<int> const& b)
			{
				return abs(a[0] - r0) + abs(a[1] - c0) < abs(b[0] - r0) + abs(b[1] - c0);
			});
		return result;
	}
};