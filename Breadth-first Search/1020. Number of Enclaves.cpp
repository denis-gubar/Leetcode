class Solution {
public:
	void clean(vector<vector<int>>& A, int X, int Y)
	{
		if (A[X][Y])
		{
			vector<int> dx = { 0, -1, 0, 1 };
			vector<int> dy = { -1, 0, 1, 0 };
			A[X][Y] = 0;
			queue<int> q;
			q.push(X); q.push(Y);
			while (!q.empty())
			{
				int x = q.front(); q.pop();
				int y = q.front(); q.pop();
				for (int z = 0; z < 4; ++z)
				{
					int nx = x + dx[z], ny = y + dy[z];
					if (nx >= 0 && nx < A.size() && ny >= 0 && ny < A[0].size() && A[nx][ny])
					{
						A[nx][ny] = 0;
						q.push(nx); q.push(ny);
					}
				}
			}
		}
	}
	int numEnclaves(vector<vector<int>>& A) {
		int result = 0;
		for (int x = 0; x < A.size(); ++x)
		{
			int y = 0;
			clean(A, x, y);
			y = A[0].size() - 1;
			clean(A, x, y);
		}
		for (int y = 0; y < A[0].size(); ++y)
		{
			int x = 0;
			clean(A, x, y);
			x = A.size() - 1;
			clean(A, x, y);
		}
		for (vector<int> const& row : A)
			for (int a : row)
				result += a;
		return result;
	}
};