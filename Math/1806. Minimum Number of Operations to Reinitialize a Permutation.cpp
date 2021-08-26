class Solution {
public:
	int reinitializePermutation(int n) {
		vector<int> A(n);
		iota(A.begin(), A.end(), 0);
		vector<int>	etalon(A), B(n);
		int result = 0;
		do 
		{
			for (int i = 0; i < n; ++i)
				if (i % 2 == 0)
					B[i] = A[i / 2];
				else
					B[i] = A[n / 2 + (i - 1) / 2];
			A = B;
			++result;
		} while (A != etalon);
		return result;
	}
};