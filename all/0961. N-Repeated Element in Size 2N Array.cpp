class Solution {
public:
	int repeatedNTimes(vector<int>& A) {
		sort(A.begin(), A.end());
		if (A[0] == A[1])
			return A[0];
		if (A.back() == A[A.size() - 2])
			return A.back();
		return A[A.size() / 2];
	}
};