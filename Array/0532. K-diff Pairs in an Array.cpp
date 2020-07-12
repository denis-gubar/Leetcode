class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		if (k < 0) return 0;
		int result = 0;
		sort(nums.begin(), nums.end());
		int a = 0, b = 1;
		while (b < nums.size())
		{
			while (b + 1 < nums.size() && nums[b] == nums[b + 1])
				++b;
			if (nums[b] - nums[a] == k)
			{
				++result;
			}
			else if (nums[b] - nums[a] > k)
			{
				bool isChanged = false;
				while (a < b && nums[b] - nums[a] > k)
					++a, isChanged = true;
				if (isChanged && a < b)
					continue;
                if (a != b)
				    ++a;
			}
			++b;
		}
		return result;
	}
};