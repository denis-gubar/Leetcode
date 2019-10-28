class Solution {
public:
	string convert( string s, int numRows ) {
		if (numRows == 1)
		{
			return s;
		}
		int n = s.size(), k = 0;
		string result(n, ' ');
		vector<int> W(n);
		int x = 0, y = 0;
		while (k < n)
		{
			for (int i = 0; i < numRows && k < n; ++i )
			{
				int w = x * n + y;
				W[k] = w;
				++x; ++k;
			}
			x -= 2; ++y;
			for (int i = numRows - 2; i > 0 && k < n; --i )
			{
				int w = x * n + y;
				W[k] = w;
				--x; ++y; ++k;
			}
		}
		cout << k << endl;
		vector<pair<int, int>> Ranks;
		for (int i = 0; i < n; ++i)
		{
			Ranks.push_back(make_pair(W[i], i));
		}
		sort( Ranks.begin(), Ranks.end() );
		for (int i = 0; i < n; ++i)
		{
			result[i] = s[Ranks[i].second];
		}
		return result;
	}
};