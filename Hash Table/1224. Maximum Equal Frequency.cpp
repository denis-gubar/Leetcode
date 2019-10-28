class Solution {
public:
	int maxEqualFreq(vector<int>& nums) {
		int result = 1;
		int N = nums.size();
		vector<int> counts(100'001);
		vector<int> inv(2);
		++counts[nums[0]];
		inv[1] = 1;
		for (int i = 1; i < N; ++i)
		{
			int oldCount = counts[nums[i]];
			int newCount = ++counts[nums[i]];
			if (oldCount)
				--inv[oldCount];
			if (newCount == inv.size())
				inv.push_back({ 0 });
			++inv[newCount];
			if (inv[1] == 1 && inv.back() * (inv.size() - 1) == i ||
				inv.size() > 2 && inv.back() == 1 && (inv[inv.size() - 2] + 1) * (inv.size() - 2) == i ||
               inv[1] == i + 1)
				result = i + 1;
		}
		return result;
	}
};
