class Solution {
public:
	int numSpecial(vector<vector<int>>& mat) {
		int result = 0;
		int N = mat.size(), M = mat[0].size();
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				if (mat[i][j] == 1)
				{
					int sum = 0;
					for (int a = 0; a < N; ++a)
						sum += mat[a][j];
					for (int b = 0; b < M; ++b)
						sum += mat[i][b];
					result += sum == 2;
				}
		return result;
	}
};