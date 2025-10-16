class Solution {
public:
	int minKBitFlips(vector<int>& A, int K) {
		int result = 0, flipCount = 0;
        int N = A.size();
		vector<int> flipEnds(N + K);
		for (int i = 0; i < N; ++i)
		{
			flipCount -= flipEnds[i];
			A[i] = (A[i] + flipCount) % 2;
			if (A[i] == 0)
			{
				if (i + K > N)
					return -1;
				++flipCount, ++result, ++flipEnds[i + K];
				A[i] = 1;
			}
		}
		return result;
	}
};