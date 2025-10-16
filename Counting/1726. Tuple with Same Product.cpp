class Solution {
public:
	int tupleSameProduct(vector<int>& nums) {
		int result = 0;
		int N = nums.size();
		unordered_map<int, int> M;
		for (int i = 0; i < N; ++i)
			for (int j = i + 1; j < N; ++j)
				++M[nums[i] * nums[j]];
		for (auto p : M)
			if (p.second > 1)
				result += p.second * (p.second - 1) * 4;
		return result;
	}
};