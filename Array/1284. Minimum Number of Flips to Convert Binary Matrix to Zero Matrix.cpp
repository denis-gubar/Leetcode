class Solution {
public:
	int minFlips(vector<vector<int>>& mat) {
		vector<int> dx{ 0, -1, 0, 1, 0 };
		vector<int> dy{ 0, 0, 1, 0, -1 };
        int m = mat.size(), n = mat[0].size();
		vector<vector<int>> target(m, vector<int>(n));
		int result = 10;
		for (int x = 0; x < (1 << (m * n)); ++x)
		{
			int count = 0;
			vector<vector<int>> grid(mat);
			for (int i = 0, k = 0; i < m; ++i)
				for (int j = 0; j < n; ++j, ++k)
				{
					if (x & (1 << k))
					{
						++count;
						for (int z = 0; z < 5; ++z)
						{
							int nx = i + dx[z];
							int ny = j + dy[z];
							if (nx >= 0 && nx < m && ny >= 0 && ny < n)
								grid[nx][ny] = 1 - grid[nx][ny];
						}
					}
				}
			if (count < result && grid == target)
				result = count;
		}
		if (result == 10) result = -1;
		return result;
	}
};