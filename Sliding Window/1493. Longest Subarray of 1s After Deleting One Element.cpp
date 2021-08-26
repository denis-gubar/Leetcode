class Solution {
public:
	int longestSubarray(vector<int>& nums) {
		int result = 0;
		map<int, int> M;
		int N = nums.size();
		int sum = 0;
		for (int i = 0; i < N; ++i)
		{
			sum += nums[i];
            if (nums[i])
			    ++M[i - sum];
		}
		for (auto p : M)
			result = max(result, p.second);
		if (M.size() > 1)
		{
			auto it = M.begin(), it2 = it;
			++it2;
			while (it2 != M.end())
			{
				if (it2->first - it->first == 1)
					result = max(result, it->second + it2->second);
				++it, ++it2;
			}
		}
		if (result == N)
			--result;
		return result;
	}
};