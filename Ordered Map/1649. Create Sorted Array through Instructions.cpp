long long temp[100'000];
long long L[100'000];
long long R[100'000];
class Solution {
public:
	void mergeSort(long long* A, int begin, int end, vector<int>& result)
	{
		int N = end - begin;
		if (N < 2) return;
		int m = N / 2;
		mergeSort(A, begin, begin + m, result);
		mergeSort(A, begin + m, end, result);
		int L = begin;
		int R = begin + m;
		for (int i = 0; i < N; ++i)
		{
			if (R == end || L != begin + m && (A[L] >> 32LL) < (A[R] >> 32LL))
			{
				temp[i] = A[L], ++L;
			}
			else
			{
				result[A[R] & ((1LL << 32LL) - 1)] += L - begin;
				temp[i] = A[R], ++R;
			}
		}
		for (int i = 0; i < N; ++i)
			A[begin + i] = temp[i];
	}
	void mergeSort2(long long* A, int begin, int end, vector<int>& result)
	{
		int N = end - begin;
		if (N < 2) return;
		int m = N / 2;
		mergeSort2(A, begin, begin + m, result);
		mergeSort2(A, begin + m, end, result);
		int L = begin;
		int R = begin + m;
		for (int i = 0; i < N; ++i)
		{
			if (R == end || L != begin + m && (A[L] >> 32LL) <= (A[R] >> 32LL))
			{
				temp[i] = A[L], ++L;
			}
			else
			{
				result[A[R] & ((1LL << 32LL) - 1)] += begin + m - L;
				temp[i] = A[R], ++R;
			}
		}
		for (int i = 0; i < N; ++i)
			A[begin + i] = temp[i];
	}
	int createSortedArray(vector<int>& instructions) {
		long long result = 0;
		int N = instructions.size();
		for (int i = 0; i < N; ++i)
			L[i] = R[i] = (static_cast<long long>(instructions[i]) << 32LL) | i;
		vector<int> left(N), right(N);
		mergeSort(L, 0, N, left);
		mergeSort2(R, 0, N, right);
		for (int i = 0; i < N; ++i)
			result += min(left[i], right[i]);
		return result % 1'000'000'007;
	}
};