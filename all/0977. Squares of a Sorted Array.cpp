class Solution {
public:
	vector<int> sortedSquares(vector<int>& A) {
		auto it = lower_bound(A.begin(), A.end(), 0);
		for (int& a : A)
			a *= a;
		reverse(A.begin(), it);
		inplace_merge(A.begin(), it, A.end());
		return A;
	}
};