class Solution {
public:
	int surfaceArea(vector<vector<int>>& grid) {
		int result = 0;
		set<vector<int>> points;
		for (int i = 0; i < grid.size(); ++i)
			for (int j = 0; j < grid[i].size(); ++j)
				for (int k = 0; k < grid[i][j]; ++k)
					points.insert({ i, j, k });
		for (const vector<int>& point : points)
		{
			for (int dx = -1; dx <= 1; dx += 2)
				if (points.find({ point[0] + dx, point[1], point[2] }) == points.end())
					++result;
			for (int dy = -1; dy <= 1; dy += 2)
				if (points.find({ point[0], point[1] + dy, point[2] }) == points.end())
					++result;
			for (int dz = -1; dz <= 1; dz += 2)
				if (points.find({ point[0], point[1], point[2] + dz }) == points.end())
					++result;
		}
		return result;
	}
};