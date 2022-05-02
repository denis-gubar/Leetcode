class Solution {
public:
	void update(vector<long long>& A, int x, long long val)
	{
		int pos = x + 1;
		while (pos < A.size())
		{
			A[pos] += val;
			pos += pos & (-pos);
		}
	}
	long long get(vector<long long> const& A, int x)
	{
		int pos = x + 1;
		long long result = 0;
		while (pos > 0)
		{
			result += A[pos];
			pos -= pos & (-pos);
		}
		return result;
	}
	long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size();
		vector<int> P(N), P2(N);
		for (int i = 0; i < N; ++i)
			P2[nums2[i]] = i;
		for (int i = 0; i < N; ++i)
			P[i] = P2[nums1[i]];
		vector<long long> B1(N + 1), B2(N + 1);
		long long result = 0;
		for (int i = 0; i < N; ++i)
		{
			int x = P[i];
			long long result1 = get(B1, x);
			long long result2 = get(B2, x);
			result += result2;
			update(B1, x, 1);
			update(B2, x, result1);
		}
        return result;
    }
};
