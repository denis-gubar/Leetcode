class Solution {
public:
	int maxScore(vector<int>& cardPoints, int k) {
		int result = 0;
		int N = cardPoints.size();
		vector<int> A{ 0 };
		partial_sum(cardPoints.begin(), cardPoints.end(), back_inserter(A));
		for (int j = 0; j <= k; ++j)
			result = max(result, A[N] - A[N - j] + A[k - j]);
		return result;
	}
};