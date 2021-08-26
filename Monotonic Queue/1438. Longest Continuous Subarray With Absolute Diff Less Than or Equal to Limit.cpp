class Solution {
public:
	int longestSubarray(vector<int>& nums, int limit) {
		multiset<int> S;
		int N = nums.size();
		int result = 0;
		int last = 0;
		for (int i = 0; i < N; ++i)
		{
			S.insert(nums[i]);
			while (*prev(S.end()) - *S.begin() > limit)
			{
				S.erase(S.find(nums[last]));
				++last;
			}
			result = max(result, i - last + 1);
		}
		return result;
	}
};