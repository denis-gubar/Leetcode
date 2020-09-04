class Solution {
public:
	int calc(vector<int> const& A, vector<int> const& V, int begin, int end, vector<vector<int>>& F)
	{
		if (F[begin][end] == -1)
		{
			if (begin >= end)
				return F[begin][end] = 0;
			if (begin + 1 == end)
				return F[begin][end] = min(V[begin], V[end]);
			int right = A[end + 1] - A[begin];
			int left = 0;
			for (int k = begin; k < end; ++k)
			{
				left += V[k];
				right -= V[k];
				int result = 0;
				if (left == right)
					result = left + max(calc(A, V, begin, k, F), calc(A, V, k + 1, end, F));
				else if (left < right)
					result = left + calc(A, V, begin, k, F);
				else
					result = right + calc(A, V, k + 1, end, F);
				F[begin][end] = max(F[begin][end], result);
			}
		}        
		return F[begin][end];
	}
	int stoneGameV(vector<int>& stoneValue) {
		int N = stoneValue.size();
		vector<int>	A{ 0 };
		partial_sum(stoneValue.begin(), stoneValue.end(), back_inserter(A));
		vector<vector<int>> F(N, vector<int>(N, -1));
		return calc(A, stoneValue, 0, N - 1, F);
	}
};