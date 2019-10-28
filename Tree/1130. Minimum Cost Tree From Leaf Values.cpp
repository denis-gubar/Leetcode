class Solution {
public:
	int calc(vector<int>::iterator start, vector<int>::iterator a, vector<int>::iterator b)
	{
		if (a == b)
			return 0;
		if (b - a == 1)
			return 0;
		int i = a - start, j = b - start - 1;
		if (!M[i][j])
		{
			int result = numeric_limits<int>::max();
			vector<int> LM, RM;
			for (vector<int>::iterator m = a; m != b; ++m)
			{
				if (LM.empty())
					LM.push_back(*m);
				else
					LM.push_back(max(*m, LM.back()));
			}
			for (vector<int>::iterator m = b; m != a; )
			{
				--m;
				if (RM.empty())
					RM.push_back(*m);
				else
					RM.push_back(max(*m, RM.back()));
			}
			reverse(RM.begin(), RM.end());
			for (vector<int>::iterator m = a; m + 1 != b; ++m)
				result = min(result, LM[m - a] * RM[m - a + 1] + calc(start, a, m + 1) + calc(start, m + 1, b));
			M[i][j] = result;
		}
		return M[i][j];
	}
	int mctFromLeafValues(vector<int>& arr) {
		int n = arr.size();
		M = vector<vector<int>>(n, vector<int>(n));
		return calc(arr.begin(), arr.begin(), arr.end());
	}
	vector<vector<int>> M;
};