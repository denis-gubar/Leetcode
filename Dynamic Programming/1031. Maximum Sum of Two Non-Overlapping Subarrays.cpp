class Solution {
public:
	int calc(vector<int> const& A, int L, int M)
	{
		int result = 0;
		int N = A.size();
		int sum = 0, pos = N - 1;
		vector<int>	best_sums(N, -1'000'001);
		for (int k = 0; k < M; ++k)
			sum += A[pos], --pos;
		best_sums[pos + 1] = sum;
		while (pos > 0)
		{
			sum -= A[pos + M];
			sum += A[pos];
			best_sums[pos] = max(best_sums[pos + 1], sum);
			--pos;
		}
		sum = 0;
		for (int k = 0; k < L; ++k)
			sum += A[k];
		result = max(result, sum + best_sums[L]);
		for (int pos = L; pos < N - 1; ++pos)
		{
			sum -= A[pos - L];
			sum += A[pos];
			result = max(result, sum + best_sums[pos + 1]);
		}
		return result;
	}
	int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {		
		return max(calc(A, L, M), calc(A, M, L));
	}
};