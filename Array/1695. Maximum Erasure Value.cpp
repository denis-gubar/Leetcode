class Solution {
public:
	int maximumUniqueSubarray(vector<int>& nums) {
		int a = 0;
		int b = 0;
		int sum = 0;
		int result = 0;
		unordered_set<int> S;
		while (b < nums.size())
		{
			int x = nums[b];
			if (S.find(x) == S.end())
			{
				S.insert(x);
				sum += x;
				result = max(result, sum);
			}
			else
			{
				while (nums[a] != x)
				{
					S.erase(nums[a]);
					sum -= nums[a];
					++a;
				}
                ++a;
			}
			++b;
		}
		return result;
	}
};