class Solution {
public:
	int largestSumAfterKNegations(vector<int>& A, int K) {
		sort(A.begin(), A.end());
		for (int i = 0; i < A.size() && K > 0 && A[i] < 0; --K, ++i)
			A[i] = -A[i];
		if (K % 2)
		{
			sort(A.begin(), A.end());
			A[0] = -A[0];
		}
		return accumulate(A.begin(), A.end(), 0);
	}
};