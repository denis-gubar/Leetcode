class Solution {
public:
	bool isMonotonic(vector<int>& A) {
		vector<int> B(A);
		sort(B.begin(), B.end());
		vector<int> C(A);
		sort(C.begin(), C.end(), greater<int>());
		return A == B || C == A;
	}
};