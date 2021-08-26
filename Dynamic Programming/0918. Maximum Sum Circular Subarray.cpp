class Solution {
public:
	int maxSubarraySumCircular(vector<int>& A) {
		int minResult = *max_element(A.begin(), A.end());
		if (minResult <= 0)
			return minResult;
		int result = minResult;
		int total = accumulate(A.begin(), A.end(), 0);
		int b = 0, sum1 = 0, sum2 = 0;
		while (b < A.size())
		{
			sum1 = max(sum1 + A[b], 0);
            sum2 = min(sum2 + A[b], 0);
			result = max({result, sum1, total - sum2});
			++b;
		}
		return result;
	}
};