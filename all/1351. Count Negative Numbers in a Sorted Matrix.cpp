class Solution {
public:
	int countNegatives(vector<vector<int>>& grid) {
		int result = 0;
		for (vector<int> const& row : grid)
			for (int x : row)
				result += x < 0;
		return result;
	}
};