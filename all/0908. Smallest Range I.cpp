class Solution {
public:
	int smallestRangeI(vector<int>& A, int K) {
		int a = *min_element(A.begin(), A.end());
		int b = *max_element(A.begin(), A.end());
		a += K, b -= K;
		int result = max(b - a, 0);
		return result;
	}
};