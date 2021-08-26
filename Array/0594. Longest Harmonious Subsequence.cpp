class Solution {
public:
	int findLHS(vector<int>& nums) {
		int result = 0;
		map<int, int> M;
		for (int n : nums)
			++M[n];
		auto it = M.begin();
		auto prev = it;
		if (it != M.end())
			++it;
		while (it != M.end())
		{
			if (it->first - prev->first == 1)
				result = max(result, it->second + prev->second);
			prev = it;
			++it;
		}
		return result;
	}
};