class Solution {
public:
	int heightChecker(vector<int>& heights) {
		int result = 0;
		vector<int> A(heights);
		sort(A.begin(), A.end());
		for (int i = 0; i < A.size(); ++i)
			result += A[i] != heights[i];
        return result;
	}
};
