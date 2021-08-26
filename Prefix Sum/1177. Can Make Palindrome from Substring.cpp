class Solution {
public:
	vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
		vector<bool> result;
		vector<vector<int>> count(s.size(), vector<int>(26));
		for (int i = 0; i < s.size(); ++i)
		{
			if (i)
				for (int j = 0; j < 26; ++j)
					count[i][j] += count[i - 1][j];
			++count[i][s[i] - 'a'];
		}
		for (vector<int> const& query : queries)
		{
			int const& left = query[0];
			int const& right = query[1];
			int const& k = query[2];
			int badChars = -2 * k;
			for (int j = 0; j < 26; ++j)
			{
				int x = count[right][j] - (left ? count[left - 1][j] : 0);
				if (x % 2)
					++badChars;
			}
			if ((right - left) % 2 == 0)
				--badChars;
			result.push_back(badChars <= 0);
		}
		return result;
	}
};