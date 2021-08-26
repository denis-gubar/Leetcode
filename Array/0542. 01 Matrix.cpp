class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		int M = matrix.size(), N = matrix[0].size();
		vector<vector<int>> result(M, vector<int>(N, 10000));
		vector<int> dx{ -1, 0, 1, 0 };
		vector<int> dy{ 0, -1, 0, 1 };
		queue<int> Q;
		for(int i = 0; i < M; ++i)
			for(int j = 0; j < N; ++j)
				if (matrix[i][j] == 0)
				{
					Q.push(i); Q.push(j);
					result[i][j] = 0;
				}
		while (!Q.empty())
		{
			int x = Q.front(); Q.pop();
			int y = Q.front(); Q.pop();
			for (int z = 0; z < 4; ++z)
			{
				int nx = x + dx[z];
				int ny = y + dy[z];
				if (nx >= 0 && nx < M && ny >= 0 && ny < N && result[nx][ny] > result[x][y] + 1)
				{
					result[nx][ny] = result[x][y] + 1;
					Q.push(nx); Q.push(ny);
				}
			}
		}
		return result;
	}
};