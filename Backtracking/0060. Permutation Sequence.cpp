class Solution {
public:
	string getPermutation(int n, int k) {
		string result;
		for (int i = 1; i <= n; ++i)
			result += '0' + i;
		for (int i = 1; i < k; ++i)
			next_permutation(result.begin(), result.end());
		return result;
	}
};