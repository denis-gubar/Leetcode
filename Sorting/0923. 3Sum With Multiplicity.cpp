class Solution {
	static const int MOD = 1000000007;
public:
	int threeSumMulti(vector<int>& A, int target) {
		long long result = 0;
		int N = A.size();
		vector<vector<int>> M(N, vector<int>(301, 0));
		for (int i = N - 1; i >= 0; --i)
		{
			if (i < N - 1)
				M[i] = M[i + 1];
			++M[i][A[i]];
		}
		for (int i = 0; i + 2 < N; ++i)
		{
			for (int j = i + 1; j + 1 < N; ++j)
			{
				int s = A[i] + A[j];
				if (s <= target)
				{
					int k = j + 1;
					result += M[k][target - s];
				}
			}
			result %= MOD;
		}
		return result;
	}
};