class Solution {
public:
	int snakesAndLadders(vector<vector<int>>& board) {
		int N = board.size();
		vector<int> M(1);
		bool flag = true;
		for (int x = N - 1; x >= 0; --x)
		{
			if (flag)
				for (int y = 0; y < N; ++y)
					M.push_back(board[x][y]);
			else
				for (int y = N - 1; y >= 0; --y)
					M.push_back(board[x][y]);
			flag = !flag;
		}
		vector<int> visited(N * N + 1, N * N + 1);
		visited[1] = 0;
		queue<int> q;
		q.push(1);
		while (!q.empty())
		{
			int pos = q.front(); q.pop();
			for (int dx = 1; dx < 7; ++dx)
				if (pos + dx <= N * N)
				{
					int newPos = pos + dx;
					if (M[newPos] == -1)
					{
						if (visited[pos] + 1 < visited[pos + dx])
						{
							visited[newPos] = visited[pos] + 1;
							q.push(newPos);
						}
					}
					else
					{
						if (visited[pos] + 1 < visited[M[newPos]])
						{
							visited[M[newPos]] = visited[pos] + 1;
							newPos = M[newPos];
							q.push(newPos);
						}
					}
				}
		}
		int result = visited[N * N];
		if (result > N * N)
			result = -1;
		return result;
	}
};
