class Solution {
public:
	int shortestBridge(vector<vector<int>>& A) {
		vector<int> dx{ 0, 1, 0, -1 };
		vector<int> dy{ 1, 0, -1, 0 };
		vector<vector<int>> M(A);
		int X = A.size(), Y = A[0].size();
		bool isCompleted = false;
		for (int i = 0; i < X && !isCompleted; ++i)
			for (int j = 0; j < Y; ++j)
				if (M[i][j] == 1)
				{
					M[i][j] = 2;
					queue<int> q;
					q.push(i); q.push(j);
					while (!q.empty())
					{
						int x = q.front(); q.pop();
						int y = q.front(); q.pop();
						for (int t = 0; t < 4; ++t)
						{
							int nx = x + dx[t];
							int ny = y + dy[t];
							if (nx >= 0 && nx < X && ny >= 0 && ny < Y && M[nx][ny] == 1)
							{
								M[nx][ny] = 2;
								q.push(nx); q.push(ny);
							}
						}
					}
					isCompleted = true;
					break;
				}
		queue<int> q;
		for (int i = 0; i < X; ++i)
			for (int j = 0; j < Y; ++j)
				if (M[i][j] == 2)
				{
					q.push(0); q.push(i); q.push(j);
				}
		while (!q.empty())
		{
			int s = q.front(); q.pop();
			int x = q.front(); q.pop();
			int y = q.front(); q.pop();
			for (int t = 0; t < 4; ++t)
			{
				int nx = x + dx[t];
				int ny = y + dy[t];
				if (nx >= 0 && nx < X && ny >= 0 && ny < Y && M[nx][ny] != 2)
				{
					if (M[nx][ny] == 1)
						return s;
					M[nx][ny] = 2;
					q.push(s + 1); q.push(nx); q.push(ny);
				}
			}
		}
		return -1;
	}
};