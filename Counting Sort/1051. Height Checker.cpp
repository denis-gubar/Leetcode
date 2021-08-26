class Solution {
public:
	int heightChecker(vector<int>& heights) {
		vector<int>	A(heights);
		sort(A.begin(), A.end());
		int result = 0;
		for (int i = 0; i < A.size(); ++i)
			result += A[i] != heights[i];
		return result;
	}
};