class Solution {
public:
	int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.empty()) return 0;
		int result = 0;
		sort(pairs.begin(), pairs.end(), [](vector<int> const& A, vector<int> const& B)
			{
				return A[1] < B[1];
			});
		int pos = pairs[0][0] - 1;
		for (vector<int> const& pair : pairs)
			if(pos < pair[0])
			{
				pos = pair[1];
				++result;
			}
		return result;
	}
};