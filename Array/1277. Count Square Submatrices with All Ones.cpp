static int F[301][301];
class Solution {
public:
	int countSquares(vector<vector<int>>& matrix) {
		int result = 0;
		int N = matrix.size(), M = matrix[0].size();
		memset(F, 0, sizeof(F));
		for (int i = N - 1; i >= 0; --i)
			for (int j = M - 1; j >= 0; --j)
				if (matrix[i][j])
                {
					F[i][j] = 1 + min({F[i + 1][j], F[i][j + 1], F[i + 1][j + 1]});
                    result += F[i][j];
                }
		return result;
	}
};