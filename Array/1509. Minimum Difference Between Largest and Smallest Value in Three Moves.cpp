class Solution {
public:
	int minDifference(vector<int>& A) {
		if (A.size() < 5)
			return 0;
		sort(A.begin(), A.end());
		int result = A.back() - A[0];
		for (int i = 0; i <= 3; ++i)
			for (int j = A.size() - 1, k = i; k <= 3; ++k, --j)
				result = min(result, A[j] - A[i]);
		return result;
	}
};