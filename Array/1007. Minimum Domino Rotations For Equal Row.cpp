class Solution {
public:
	int minDominoRotations(vector<int>& A, vector<int>& B) {
		int N = A.size();
		int result = N + 1;
		vector<int> count(7);
		for (int i = 0; i < N; ++i)
		{
			++count[A[i]];
			if (A[i] != B[i])
				++count[B[i]];
		}
		for (int j = 1; j < 7; ++j)
			if (count[j] == N)
		{
			int swapsA = 0, swapsB = 0;
			for (int i = 0; i < N; ++i)
			{
				if (A[i] != j)
					++swapsA;
				if (B[i] != j)
					++swapsB;
			}
			result = min({ result, swapsA, swapsB });
		}
		if (result > N)
			result = -1;
		return result;
	}
};