class Solution {
public:
	void parse(int node, int& level, int& pos, int& value)
	{
		level = node / 100;
		pos = node % 100 / 10;
		value = node % 10;
	}
	int calc(vector<int> const& nums, int root, int sum = 0)
	{
		int level, pos, value;
		parse(root, level, pos, value);		
		sum += value;
		auto it = lower_bound(nums.begin(), nums.end(), (level + 1) * 100 + (2 * pos - 1) * 10);
		int result = sum;
		int children = -1;
		while (it != nums.end())
		{
			int nLevel, nPos, nValue;
			parse(*it, nLevel, nPos, nValue);
			if (nLevel == level + 1 && (nPos == 2 * pos - 1 || nPos == 2 * pos))
			{
				if (children < 0) children = 0;
				children += calc(nums, *it, sum);
			}
            ++it;
		}
		if (children >= 0)
			result = children;
		return result;
	}
	int pathSum(vector<int>& nums) {
		return calc(nums, nums[0], 0);
	}
};