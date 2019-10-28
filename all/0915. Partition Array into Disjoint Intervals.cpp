class Solution {
public:
	int partitionDisjoint(vector<int>& A) {
		vector<int> M(A), m(A);
		for (int i = 1; i < A.size(); ++i)
			M[i] = max(A[i], M[i - 1]);
		for (int i = A.size() - 1; i > 0; --i)
			m[i - 1] = min(A[i - 1], m[i]);
		for (int result = 1; result < A.size(); ++result)
			if (M[result - 1] <= m[result])
				return result;
		return -1;
	}
};
