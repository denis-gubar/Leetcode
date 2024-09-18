class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
		vector<int> M;
        M.reserve(N);
		for (int n : nums)
		{
			auto it = lower_bound(M.begin(), M.end(), n);
			if (it == M.end())
				M.push_back(n);
			else             
				*it = n;
		}
		return M.size();
	}
};