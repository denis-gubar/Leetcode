class Solution {
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<vector<int>> result;
		int N = nums.size();
		vector<int> current;
		for (int mask = 1; mask < (1 << N); ++mask)
		{
			for (int k = 0; k < N; ++k)
				if (mask & (1 << k))
					if (current.empty() || current.back() <= nums[k])
						current.push_back(nums[k]);
			if (current.size() > 1)
				result.push_back(current);
			current.clear();
		}
		sort(result.begin(), result.end());
		result.erase(unique(result.begin(), result.end()), result.end());
		return result;
	}
};