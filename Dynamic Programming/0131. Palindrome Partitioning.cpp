class Solution {
public:
	bool isPalindrome(int a, int b)
	{
		while (a < b)
		{
			if (S[a] != S[b])
				return false;
			++a; --b;
		}
		return true;
	}
	vector<vector<int>> calc(int a)
	{
		vector<vector<int>> result;
		for (int m = a; m < N; ++m)
			if (P[a][m])
			{
				vector<int> current{ m - a + 1 };
				if (m + 1 < N)
				{
					vector<vector<int>> suffix = calc(m + 1);
					for (const vector<int>& v : suffix)
					{
						result.push_back(current);
						copy(v.begin(), v.end(), back_inserter(result.back()));
					}
				}
				else
					result.push_back(current);
			}
		return result;
	}
	vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
		S = s;
		N = s.size();
		P = vector<vector<bool>>(N, vector<bool>(N));
		for (int a = 0; a < N; ++a)
			for (int b = a; b < N; ++b)
				P[a][b] = isPalindrome(a, b);
		vector<vector<int>> A = calc(0);
		for (int i = 0; i < A.size(); ++i)
		{
			vector<string> current;
			int pos = 0;
			for (int j = 0; j < A[i].size(); ++j)
			{
				current.push_back(S.substr(pos, A[i][j]));
				pos += A[i][j];
			}
			result.push_back(current);
		}
		return result;
	}
	int N;
	string S;
	vector<vector<bool>> P;
};