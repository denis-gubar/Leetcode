class Solution {
public:
	int minDeletionSize(vector<string>& A) {
		int result = 0;
		int N = A.size(), M = A[0].size();
		for (int j = 0; j < M; ++j)
		{
			bool flag = true;
			for (int i = 0; i + 1 < N; ++i)
			{
				flag &= A[i][j] <= A[i + 1][j];
				if (!flag)
					break;
			}
			if (flag)
				++result;
		}
		return M - result;
	}
};