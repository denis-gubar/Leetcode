class Solution {
public:
	int findNumbers(vector<int>& nums) {
		int result = 0;
		for (int n : nums)
			result += to_string(n).size() % 2 == 0;
		return result;
	}
};