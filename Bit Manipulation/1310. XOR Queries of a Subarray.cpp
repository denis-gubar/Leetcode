class Solution {
public:
	vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
		vector<int> result;
		vector<int> A{ 0 };
		partial_sum(arr.begin(), arr.end(), back_inserter(A), bit_xor<int>());
		for (vector<int> const& query : queries)
			result.push_back(A[query[1] + 1] ^ A[query[0]]);
		return result;
	}
};