class Solution {
public:
	int minOperations(vector<int>& nums) {
		int N = nums.size();
		int result = N;
		set<int> S;
		for (int x : nums)
			S.insert(x);
		int delta = 0;
		auto it = S.begin();
		for (int x : S)
		{
			while (it != S.end() && *it - x <= N - 1)
			{
				++it;
				++delta;
			}
			result = min(result, N - delta);
			--delta;
		}
		return result;
	}
};