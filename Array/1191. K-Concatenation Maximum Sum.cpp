class Solution {
public:
	int kConcatenationMaxSum(vector<int>& arr, int k) {
		const long long MOD = 1'000'000'007;
		long long period = accumulate(arr.begin(), arr.end(), 0);
		long long result = 0;
		if (period > 0)
			result = period * k;
		vector<int> A;
		partial_sum(arr.begin(), arr.end(), back_inserter(A));
		long long M = 0;
		int a = 0;
		for (long long x : A)
			if (a < x)
				M = max(M, x - a);
			else
				a = x;
		result = max(result, M + max(period, 0LL) * (k - 1));
		if (k > 1)
		{
			for (int i = 0; i < arr.size(); ++i)
				A.push_back(A.back() + arr[i]);
			long long M2 = M;
			int a = 0;
			for (long long x : A)
				if (a < x)
					M2 = max(M2, x - a);
				else
					a = x;
			result = max(result, M2);
		}
		return result % MOD;
	}
};