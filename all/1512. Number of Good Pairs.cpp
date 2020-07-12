class Solution {
public:
	int numIdenticalPairs(vector<int>& nums) {
		unordered_map<int, int> M;
		for (int n : nums)
			++M[n];
		int result = 0;
		for (auto p : M)
			result += p.second * (p.second - 1) / 2;
		return result;
	}
};