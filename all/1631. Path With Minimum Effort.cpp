class Solution {
public:
	int minimumEffortPath(vector<vector<int>>& heights) {
		int N = heights.size(), M = heights[0].size();
		vector<vector<int>> F(N, vector<int>(M, 1 << 30));
		vector<int>	dx{ 0, -1, 0, 1 };
		vector<int>	dy{ -1, 0, 1, 0 };
		F[0][0] = 0;
		priority_queue<pair<int, pair<int, int>>> Q;
		Q.push({ 0, {0, 0} });
		while (!Q.empty())
		{
			int w = -Q.top().first;
			int x = Q.top().second.first;
			int y = Q.top().second.second;
			Q.pop();
			if (F[x][y] < w)
				continue;
			for (int z = 0; z < 4; ++z)
			{
				int nx = x + dx[z];
				int ny = y + dy[z];
				if (nx >= 0 && nx < N && ny >= 0 && ny < M && 
					F[nx][ny] > max(F[x][y], abs(heights[x][y] - heights[nx][ny])))
				{
					F[nx][ny] = max(F[x][y], abs(heights[x][y] - heights[nx][ny]));
					Q.push({ -F[nx][ny], {nx, ny} });
				}
			}
		}
		return F.back().back();
	}
};