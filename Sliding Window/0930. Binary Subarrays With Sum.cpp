class Solution {
public:
	int numSubarraysWithSum(vector<int>& A, int S) {
		int result = 0;
		int N = A.size();
		vector<int> zeroes(N);
		for (int i = N - 1; i >= 0; --i)
			if (A[i] == 0)
				zeroes[i] = 1 + (i < N - 1 ? zeroes[i + 1] : 0);
		if (S == 0)
			return accumulate(zeroes.begin(), zeroes.end(), 0);
		int k = 0, a = 0, b = 0;
		while (b < N)
		{
			k += A[b];
			if (k == S)
				result += zeroes[a] + 1;
			else if (k > S)
			{
				while (A[a] == 0)
					++a;
				++a;
				--k;
				result += zeroes[a] + 1;
			}
			++b;
		}
		return result;
	}
};