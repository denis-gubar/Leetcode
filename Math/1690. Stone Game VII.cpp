class Solution {
public:
	int calc(vector<int>& M, vector<int> const& stones, vector<int> const& A, int a, int b)
	{
		if (a == b)
			return 0;
		if (M[a * 1001 + b] < 0)
		{
			int left = A[b + 1] - A[a + 1] - calc(M, stones, A, a + 1, b);
			int right = A[b] - A[a] - calc(M, stones, A, a, b - 1);
			M[a * 1001 + b] = max(left, right);
		}
		return M[a * 1001 + b];
	}
	int stoneGameVII(vector<int>& stones) {
		vector<int> A{ 0 };
		partial_sum(stones.begin(), stones.end(), back_inserter(A));
		vector<int> M(1001 * 1001, -1);
		return calc(M, stones, A, 0, stones.size() - 1);
	}
};