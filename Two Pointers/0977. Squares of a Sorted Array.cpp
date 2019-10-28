class Solution {
public:
	vector<int> sortedSquares(vector<int>& A) {
		vector<int> result(A);
		for (int& a : result)
			a *= a;
		sort(result.begin(), result.end());
		return result;
	}
};