class Solution {
public:
	double knightProbability(int N, int K, int r, int c) {
		vector<vector<double>> F(N, vector<double>(N));
		vector<int> dx{ -2, -2, -1, -1, 1, 1, 2, 2 };
		vector<int> dy{ -1, 1, -2, 2, -2, 2, -1, 1 };
		F[r][c] = 1.0;
		for (int k = 0; k < K; ++k)
		{
			vector<vector<double>> NF(N, vector<double>(N));
			for(int i = 0; i < N; ++i)
				for(int j = 0; j < N; ++j)
					if (F[i][j])
						for (int z = 0; z < 8; ++z)
						{
							int nx = i + dx[z];
							int ny = j + dy[z];
							if (nx >= 0 && nx < N && ny >= 0 && ny < N)
								NF[nx][ny] += 0.125 * F[i][j];
						}
			F = move(NF);
		}
		double result = 0.0;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				result += F[i][j];
		return result;
	}
};