class Solution {
public:
	int findNumberOfLIS(vector<int>& nums) {
		if (nums.empty()) return 0;
		int N = nums.size();
		vector<int> max_length(N, 1), count(N, 1);
		for(int i = 0; i < N; ++i)
			for(int j = i + 1; j < N; ++j)
				if (nums[j] > nums[i] && max_length[i] + 1 >= max_length[j])
				{
					if (max_length[i] + 1 > max_length[j])
						max_length[j] = max_length[i] + 1, count[j] = count[i];
					else
						count[j] += count[i];
				}
		int result = 0;
		int best_value = *max_element(max_length.begin(), max_length.end());
		for (int i = 0; i < N; ++i)
			if (max_length[i] == best_value)
				result += count[i];
		return result;
	}
};