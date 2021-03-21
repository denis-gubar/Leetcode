class Solution {
public:
	bool checkPowersOfThree(int n) {
		vector<int> A{ 1 };
		while (A.back() * 3 < 10'000'000)
			A.push_back(A.back() * 3);
		int N = A.size();
		for (int mask = 1; mask < (1 << N); ++mask)
		{
			int sum = 0;
			for (int k = 0; k < N; ++k)
				if (mask & (1 << k))
					sum += A[k];
			if (sum == n)
				return true;
		}
		return false;
	}
};