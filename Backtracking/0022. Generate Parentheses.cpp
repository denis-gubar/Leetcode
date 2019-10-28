class Solution {
public:
	vector<vector<string>> result{ { "" } };
	void calc(int n)
	{
		if (result.size() > n)
			return;
		result.push_back({});
		for (int i = 0; i < n; ++i)
			for (const string& a : result[i])
			{
				int j = n - i - 1;
				for (const string& b : result[j])
					result[n].push_back("(" + a + ")" + b);
			}
	}
	vector<string> generateParenthesis(int n) {
		for (int i = 1; i <= n; ++i)
			calc(i);
		return result[n];
	}
};