class Solution {
public:
	int projectionArea(vector<vector<int>>& grid) {
		set<pair<int, int>> xy, xz, yz;
		for (int i = 0; i < grid.size(); ++i)
			for (int j = 0; j < grid[i].size(); ++j)
			{
				int x = i, y = j, z = grid[x][y];
				if (z)
					xy.insert({ x, y });
				for (int k = 1; k <= z; ++k)
				{
					xz.insert({ x, k });
					yz.insert({ y, k });
				}
			}
		return xy.size() + xz.size() + yz.size();
	}
};
