class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> result;
		if (nums.empty()) return result;
		int start = nums[0], finish = nums[0];
		auto add = [&start, &finish, &result]()
		{
			if (start == finish)
				result.push_back(to_string(start));
			else
				result.push_back(to_string(start) + "->" + to_string(finish));
		};
		for(int i = 1; i < nums.size(); ++i)
		{
			if (finish + 1LL == nums[i])
			{
				finish = nums[i];
				continue;
			}
			else
			{
				add();
				start = finish = nums[i];
			}
		}
		add();
		return result;
	}
};