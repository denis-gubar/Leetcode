class Solution {
public:
	int largestPerimeter(vector<int>& A) {
		int result = 0;
		int N = A.size();
		sort(A.begin(), A.end());
		for(int i = N - 1; i >= N - 100 && i >= 0; --i)
			for (int j = i - 1; j > 0; --j)
			{
				if (A[i] < A[j] + A[j - 1])
					result = max(result, A[i] + A[j] + A[j - 1]);
			}
		return result;
	}
};