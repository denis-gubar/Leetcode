class Solution {
public:
	int maxSum(vector<int>& A, vector<int>& B) {
		int MOD = 1'000'000'007;
		long long result = 0;
		vector<int>	X(A);
		copy(B.begin(), B.end(), back_inserter(X));
		sort(X.begin(), X.end());
		X.resize(unique(X.begin(), X.end()) - X.begin());
		int N = X.size();
		vector<vector<long long>> F(2, vector<long long>(N + 1));
		int a = 0, b = 0;
		for (int i = 0; i < N; ++i)
		{
            F[0][i + 1] = F[0][i];
            F[1][i + 1] = F[1][i];
			if (a < A.size() && X[i] == A[a])
				F[0][i + 1] = max(F[0][i + 1], F[0][i] + A[a]);
			if (b < B.size() && X[i] == B[b])
				F[1][i + 1] = max(F[1][i + 1], F[1][i] + B[b]);
			if (a < A.size() && X[i] == A[a] && b < B.size() && X[i] == B[b])
			{
				F[1][i + 1] = max(F[1][i + 1], F[0][i] + A[a]);
				F[0][i + 1] = max(F[0][i + 1], F[1][i] + B[b]);
			}
			while (a < A.size() && A[a] <= X[i])
				++a;
			while (b < B.size() && B[b] <= X[i])
				++b;
		}
		result = max(F[0][N], F[1][N]);
		return result % MOD;
	}
};