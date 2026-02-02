class Solution {
public:
	int longestSubsequence(vector<int>& nums) {
		size_t result = 0;
		int const N = nums.size();
		vector<int> M;
		M.reserve(N);
		for (int k = 0; k < 30; ++k)
		{
			M.clear();
			for (int n : nums)
				if (n & (1 << k))
				{
					auto it = lower_bound(M.begin(), M.end(), n);
					if (it == M.end())
						M.push_back(n);
					else
						*it = n;
				}
			result = max(result, M.size());
		}
		return result;
	}
};
