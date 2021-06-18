class Solution {
public:
	vector<int> mostCompetitive(vector<int>& nums, int k) {
		vector<int> result;
		int N = nums.size();
		int passes = N - k;
		int i = 0;
		while(i < N)
		{
			if (passes == 0 || result.empty() || result.back() <= nums[i])
			{
				result.push_back(nums[i]);
				++i;
			}
			else
			{
				--passes;
				result.pop_back();
			}
		}
        result.resize(k);
		return result;
	}
};