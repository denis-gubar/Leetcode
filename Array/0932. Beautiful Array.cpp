class Solution {
public:
	vector<int> calc(int n, unordered_map<int, vector<int>>& M)
	{
		if (M.find(n) == M.end())
		{
			vector<int> result;
			result.reserve(n);
			vector<int> left = calc((n + 1) / 2, M);
			vector<int> right = calc(n / 2, M);
			for (int x : left)
				result.push_back(2 * x - 1);
			for (int x : right)
				result.push_back(2 * x);
			M[n] = move(result);
		}
		return M[n];
	}
	vector<int> beautifulArray(int n) {
		unordered_map<int, vector<int>> M;
		M[1] = { 1 };
		return calc(n, M);
	}
};
