class Solution {
public:
	int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
		int result = 0;
		int N = grid1.size(), M = grid1[0].size();
		vector<vector<int>> islands1, islands2;
		auto calc = [N, M](vector<vector<int>>& grid, vector<vector<int>>& island)
		{
			vector<int> dx{ -1, 0, 1, 0 };
			vector<int> dy{ 0, -1, 0, 1 };
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < M; ++j)
					if (grid[i][j] == 1)
					{
						island.push_back({});
						grid[i][j] = 99 + island.size();
						island.back().push_back(i * 1000 + j);
						queue<int> Q;
						Q.push(i); Q.push(j);
						while (!Q.empty())
						{
							int x = Q.front(); Q.pop();
							int y = Q.front(); Q.pop();
							for (int z = 0; z < 4; ++z)
							{
								int nx = x + dx[z];
								int ny = y + dy[z];
								if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] == 1)
								{
									grid[nx][ny] = 99 + island.size();
									island.back().push_back(nx * 1000 + ny);
									Q.push(nx); Q.push(ny);
								}
							}
						}
					}
		};
		calc(grid1, islands1);
		calc(grid2, islands2);
		for (int i = 0; i < islands2.size(); ++i)
		{
			int x = islands2[i][0] / 1000;
			int y = islands2[i][0] % 1000;
			int G = grid1[x][y] - 100;
			for (int j = 1; G >= 0 && j < islands2[i].size(); ++j)
			{
				int x = islands2[i][j] / 1000;
				int y = islands2[i][j] % 1000;
				int F = grid1[x][y] - 100;
				if (F != G)
					G = -100;
			}
			if (G >= 0)
                ++result;
		}
		return result;
	}
};