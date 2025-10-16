class Solution {
public:
	int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
		vector<int>	dx{ 0, -1, 0, 1 };
		vector<int>	dy{ -1, 0, 1, 0 };
		int N = maze.size(), M = maze[0].size();
		vector<vector<vector<bool>>> visited(5, vector<vector<bool>>(N, vector<bool>(M)));
		deque<int> Q;
		Q.push_back(start[0]); Q.push_back(start[1]); Q.push_back(4); Q.push_back(0);
		visited[4][start[0]][start[1]] = 0;
		while (!Q.empty())
		{
			int x = Q.front(); Q.pop_front();
			int y = Q.front(); Q.pop_front();
			int d = Q.front(); Q.pop_front();
			int t = Q.front(); Q.pop_front();
			if (x == destination[0] && y == destination[1] && d == 4)
				return t;
			for (int z = 0; z < 4; ++z)
				if (d == 4 || d == z)
				{
					int nx = x + dx[z];
					int ny = y + dy[z];
					if (nx >= 0 && nx < N && ny >= 0 && ny < M && maze[nx][ny] == 0)
					{
						if (visited[z][nx][ny])
							continue;
						visited[z][nx][ny] = true;
						Q.push_back(nx); Q.push_back(ny); Q.push_back(z); Q.push_back(t + 1);
					}
					else
					{
						if (visited[4][x][y])
							continue;
						visited[4][x][y] = true;
						Q.push_front(t); Q.push_front(4); Q.push_front(y); Q.push_front(x);
					}
				}
		}
		return -1;
	}
};