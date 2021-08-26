class Solution {
public:
	int minDeletionSize(vector<string>& A) {
		int N = A.size(), M = A[0].size();
		vector<string> S(N);
		for (int j = 0; j < M; ++j)
		{
			vector<string> current(S);
			for (int i = 0; i < N; ++i)
				current[i] += A[i][j];
			if (is_sorted(current.begin(), current.end()))
				S.swap(current);
		}
		return M - S[0].size();
	}
};