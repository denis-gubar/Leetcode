class Solution {
public:
	int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
		int N = nums1.size();
		int result = 1;
		int a = 0, b = 1;
		vector<int> nums3(N, 1 << 30), A(N);
		iota(A.begin(), A.end(), 0);
		int j = 0;
		for (int i = 1; i < N; ++i)
		{
			if (min(nums1[i - 1], nums2[i - 1]) > min(nums1[i], nums2[i]))
				j = i;
			A[i] = j;
		}
		nums3[0] = min(nums1[0], nums2[0]);
		while (b < N)
		{
			if (nums3[b - 1] <= max(nums1[b], nums2[b]))
			{
				if (nums3[b - 1] <= min(nums1[b], nums2[b]))
					nums3[b] = min(nums1[b], nums2[b]);
				else
					nums3[b] = max(nums1[b], nums2[b]);
				result = max(result, b - a + 1);
			}
			else
			{
				if (min(nums1[b - 1], nums2[b - 1]) <= max(nums1[b], nums2[b]))
				{
					a = A[b - 1];
					for (int i = a; i < b; ++i)
						nums3[i] = min(nums1[i], nums2[i]);
					continue;
				}
				a = b;
				nums3[b] = min(nums1[b], nums2[b]);
			}
			++b;
		}
		return result;
	}
};
