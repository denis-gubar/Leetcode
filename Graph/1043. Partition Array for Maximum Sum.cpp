class Solution {
public:
	int maxSumAfterPartitioning(vector<int>& A, int K) {
		vector<int> M(A.size() + 1);
		for (int i = 0; i < A.size(); ++i)
		{
			int maximum = A[i];
			for (int k = 1; k <= K && k - 1 <= i; ++k)
			{
				maximum = max(maximum, A[i - k + 1]);
				M[i + 1] = max(M[i + 1], M[i + 1 - k] + maximum * k);
			}
		}
		return M.back();
	}
};