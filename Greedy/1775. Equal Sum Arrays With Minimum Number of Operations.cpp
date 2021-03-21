class Solution {
public:
	int minOperations(vector<int>& nums1, vector<int>& nums2) {
		int result = 0;
		int N = nums1.size(), M = nums2.size();
		if (N * 6 < M || M * 6 < N)
			return -1;
		vector<int> A(7), B(7);
		vector<int>	I{ 0, 1, 2, 3, 4, 5, 6 };
		for (int x : nums1)
			++A[x];
		for (int x : nums2)
			++B[x];
		int totalA = inner_product(A.begin(), A.end(), I.begin(), 0);
		int totalB = inner_product(B.begin(), B.end(), I.begin(), 0);
		if (totalA == totalB)
			return 0;
		if (totalB < totalA)
		{
			swap(totalA, totalB);
			swap(A, B);
		}
		for (int delta = 5; totalA < totalB && delta >= 1; --delta)
		{
			for (int x = 1; x + delta <= 6 && totalA < totalB; ++x)
			{
				int k = min(A[x], (totalB - totalA + delta - 1) / delta);
				A[x] -= k;
				totalA += k * delta;
                result += k;
			}
			for (int x = 6; x - delta >= 1 && totalA < totalB; --x)
			{
				int k = min(B[x], (totalB - totalA + delta - 1) / delta);
				B[x] -= k;
				totalB -= k * delta;
                result += k;
			}
		}
		return result;
	}
};