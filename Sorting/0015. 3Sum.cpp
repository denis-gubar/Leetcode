class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		int N = nums.size();
		for (int i = 0; i + 2 < N; ++i)
		{
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
			int j = i + 1;
			int k = N - 1;
			while (j < k)
			{
				int sum = nums[i] + nums[j] + nums[k];
				if (sum == 0)
				{
					result.push_back({ nums[i], nums[j], nums[k] });
					while (j < k && nums[j + 1] == nums[j])
						++j;
					while (j < k && nums[k - 1] == nums[k])
						--k;
                    ++j, --k;
				}
				else if (sum < 0)
					++j;
				else
					--k;
			}
		}
		return result;
	}
};