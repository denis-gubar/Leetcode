class Solution {
public:
	int twoSumLessThanK(vector<int>& A, int K) {
		int result = -1;
		for(int i = 0; i < A.size(); ++i)
			for (int j = i + 1; j < A.size(); ++j)
			{
				int S = A[i] + A[j];
				if (S < K)
					result = max(result, S);
			}
		return result;
	}
};