class Solution {
public:
	int maximumGap(vector<int>& nums) {
		int N = nums.size();
		if (N < 2)
			return 0;
		int result = 0;
		int a = *min_element(nums.begin(), nums.end());
		int b = *max_element(nums.begin(), nums.end());
		if (a == b)
			return 0;
		int part = (b - a + N - 1) / N;
		vector<int> A(N + 1, 1 << 30);
		vector<int> B(N + 1, 0);
		for (int n : nums)
		{
			int bucket = (n - a) / part;
			A[bucket] = min(A[bucket], n);
			B[bucket] = max(B[bucket], n);
		}
		int last = 0;
		for (int i = 0; i <= N; ++i)
			if (B[i] > 0)
			{
				result = max(result, A[i] - B[last]);
				last = i;
			}
		return result;
	}
};