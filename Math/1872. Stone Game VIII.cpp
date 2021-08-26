class Solution {
public:
	int stoneGameVIII(vector<int>& stones) {
		vector<int> A;
		int N = stones.size();
		partial_sum(stones.begin(), stones.end(), back_inserter(A));
		int result = A[N - 1];
		for (int i = N - 2; i > 0; --i)
			result = max(result, A[i] - result);
		return result;
	}
};