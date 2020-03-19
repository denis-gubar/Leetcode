class Solution {
public:
	int findBestValue(vector<int>& arr, int target) {
		int result = 0, best = 1 << 30;
		sort(arr.begin(), arr.end());
		vector<long long> A;
		partial_sum(arr.begin(), arr.end(), back_inserter(A));
		for (long long x = -200'000; x <= 200'000; ++x)
		{
			int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
			long long sum = 0;
			if (pos > 0)
				sum += A[pos - 1];
			sum += x * (A.size() - pos);
			sum = abs(sum - target);
			if (sum < best)
			{
				best = sum;
				result = x;
			}
		}
		return result;
	}
};