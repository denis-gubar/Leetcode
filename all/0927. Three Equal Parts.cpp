class Solution {
public:
	vector<int> threeEqualParts(vector<int>& A) {
		if (accumulate(A.begin(), A.end(), 0) == 0)
			return { 0, 2 };
		int N = A.size();
		A.push_back(2);
		int I = 0, firstOne = N;
		while (true)
		{
			if (firstOne == N && A[I] == 1)
				firstOne = I;
			if (firstOne < N)
			{
				if ((I - firstOne + 1) * 2 > N - I - 1)
					break;
				int J = I + 1;
				while (A[J] == 0)
					++J;
				if (equal(A.begin() + firstOne, A.begin() + I + 1, A.begin() + J))
				{
					int K = J + I - firstOne + 1;
					while (A[K] == 0)
						++K;
					if (N - K == I - firstOne + 1 && equal(A.begin() + firstOne, A.begin() + I + 1, A.begin() + K))
						return { I, J + I - firstOne + 1 };
				}
			}
			++I;
		}
		return { -1, -1 };
	}
};