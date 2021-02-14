class Solution {
public:
	int sumOfUnique(vector<int>& nums) {
		int result = 0;
		unordered_map<int, int> M;
		for (int n : nums)
			++M[n];
		for (auto [x, count] : M)
			if (count == 1)
				result += x;
		return result;
	}
};