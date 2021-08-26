class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		int result = 0;
		unordered_set<int> S(nums.begin(), nums.end());
		for (int n: S)
		{
			if (S.find(n - 1) != S.end())
				continue;
			int count = 1;
			while (S.find(n + count) != S.end())
				++count;
			result = max(result, count);
		}
		return result;
	}
};