class Solution {
public:
	vector<int> minSubsequence(vector<int>& nums) {
		vector<int> result;
		vector<pair<int, int>> P;
		for (int i = 0; i < nums.size(); ++i)
			P.emplace_back(nums[i], i);
		sort(P.begin(), P.end());		
		int total = accumulate(nums.begin(), nums.end(), 0);
		for (int i = nums.size() - 1, sum = 0; i >= 0; --i)
			if (sum * 2 <= total)
			{
				sum += P[i].first;
				result.emplace_back(P[i].first);
			}
		return result;
	}
};