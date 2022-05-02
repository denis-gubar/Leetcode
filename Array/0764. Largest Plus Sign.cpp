int A[502][502][4];
class Solution {
public:
	int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
		int result = 0;
		vector<vector<bool>> M(N + 2, vector<bool>(N + 2));
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				M[i][j] = true;
		for (const auto& m : mines)
			M[m[0] + 1][m[1] + 1] = 0;
		vector<int> dx = { 0, 1, 0, -1 };
		vector<int> dy = { 1, 0, -1, 0 };
		memset(A, 0, sizeof(A));
		for (int z = 0; z < 4; ++z)
			for (int i = 1; i <= N; ++i)
				for (int j = 1; j <= N; ++j)
					if (M[i][j] && !M[i - dx[z]][j - dy[z]])
					{
						int k = 0;
						while (M[i + k * dx[z]][j + k * dy[z]])
						{
							A[i + k * dx[z]][j + k * dy[z]][(z + 2) % 4] = k + 1;
							++k;
						}
					}
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				if (M[i][j])
					result = max(result, *min_element(&A[i][j][0], &A[i][j][0] + 4));
		return result;
	}
};