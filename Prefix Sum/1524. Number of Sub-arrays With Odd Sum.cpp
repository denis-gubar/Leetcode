class Solution {
public:
	int numOfSubarrays(vector<int>& arr) {
		int MOD = 1'000'000'007;
		int N = arr.size();
		long long result = 0;
		for (int& x : arr)
			x %= 2;
		vector<int>	A{ 0 }, X(2);
		partial_sum(arr.begin(), arr.end(), back_inserter(A));
		for (int i = 0; i <= N; ++i)
		{
			result += X[1 - A[i] % 2];
			++X[A[i] % 2];
		}
		return result % MOD;
	}
};