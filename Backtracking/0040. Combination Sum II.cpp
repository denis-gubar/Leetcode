class Solution {
public:
	void calc(map<int, int> const& M, vector<int>& A, int limit, int target)
	{
		if (target == 0)
		{
			result.push_back(A);
			return;
		}
		for (auto it = M.upper_bound(limit); it != M.end() && it->first <= target; ++it)
		{
			int z = 0;
			for (int k = 1; k <= it->second && it->first * k <= target; ++k)
			{
				A.push_back(it->first);
				calc(M, A, it->first, target - k * it->first);
				++z;
			}
			for (int k = 0; k < z; ++k)
				A.pop_back();
		}
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		result.clear();
		map<int, int> M;
		for (int x : candidates)
			++M[x];
		vector<int> A;
		calc(M, A, 0, target);
		return result;
	}
	vector<vector<int>> result;
};