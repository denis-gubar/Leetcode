class Solution {
public:
	int calc(const vector<int>& nums, int pos, int S)
	{
		if (pos == nums.size())
			return S == 0;
		if (visited[pos].find(S) != visited[pos].end())
			return visited[pos][S];
		return visited[pos][S] = calc(nums, pos + 1, S - nums[pos]) + calc(nums, pos + 1, S + nums[pos]);
	}
	int findTargetSumWays(vector<int>& nums, int S) {
		visited = vector<unordered_map<int, int>>(nums.size());
		return calc(nums, 0, S);
	}
	vector<unordered_map<int, int>> visited;
};