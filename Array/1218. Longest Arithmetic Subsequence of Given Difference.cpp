class Solution {
public:
	int longestSubsequence(vector<int>& arr, int difference) {
		int result = 0;
		unordered_map<int, int> M;
        M.reserve(arr.size());
		for (int a : arr)
			result = max(result, M[a] = max(M[a], 1 + M[a - difference]));
		return result;
	}
};