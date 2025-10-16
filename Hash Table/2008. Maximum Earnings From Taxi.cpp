class Solution {
public:
	long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
		vector<long long> F(n + 1);
		vector<vector<int>> A(n + 1);
		for (vector<int> const& r : rides)
		{
			int const& start = r[0];
			int const& end = r[1];
			int const& tip = r[2];
			A[start].push_back(end);
			A[start].push_back(tip);
		}
		for (int i = 1; i <= n; ++i)
		{
			F[i] = max(F[i - 1], F[i]);
			for (int k = 0; k < A[i].size(); k += 2)
			{
				int const& start = i;
				int const& end = A[i][k];
				int const& tip = A[i][k + 1];
				F[end] = max(F[end], F[start] + end - start + tip);
			}
		}
		return F[n];
	}
};