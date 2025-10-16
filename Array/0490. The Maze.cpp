class Solution {
public:
	bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
		int N = maze.size(), M = maze[0].size();
		vector<int>	dx{ 0, -1, 0, 1 };
		vector<int>	dy{ -1, 0, 1, 0 };
		queue<int> Q;
		vector<vector<vector<bool>>> visited(5, vector<vector<bool>>(N, vector<bool>(M)));
		Q.push(start[0]); Q.push(start[1]); Q.push(4);
		visited[4][start[0]][start[1]] = true;
		while (!Q.empty())
		{
			int x = Q.front(); Q.pop();
			int y = Q.front(); Q.pop();
			int d = Q.front(); Q.pop();
			if (x == destination[0] && y == destination[1] && d == 4)
				return true;
			for (int z = 0; z < 4; ++z)
				if (d == 4 || z == d)
				{
					int nx = x + dx[z];
					int ny = y + dy[z];
					if (nx >= 0 && nx < N && ny >= 0 && ny < M && maze[nx][ny] == 0)
					{
						if (!visited[z][nx][ny])
						{
							Q.push(nx); Q.push(ny); Q.push(z);
							visited[z][nx][ny] = true;
						}
					}
					else if (!visited[4][x][y])
					{
						Q.push(x); Q.push(y); Q.push(4);
						visited[4][x][y] = true;
					}
				}
		}
		return false;
	}
};