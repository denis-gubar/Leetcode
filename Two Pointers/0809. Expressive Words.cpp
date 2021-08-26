class Solution {
public:
	vector<pair<char, int>> calc(string const& word)
	{
		vector<pair<char, int>> result;
		for (int i = 0; i < word.size(); )
		{
			char x = word[i];
			int xcount = 0;
			while (i < word.size() && x == word[i])
				++i, ++xcount;
			result.push_back({ x, xcount });
		}
		return result;
	}
	int expressiveWords(string S, vector<string>& words) {
		int result = 0;
		vector<pair<char, int>> P = calc(S);
		for (string const& word : words)
		{
			vector<pair<char, int>> A = calc(word);
			if (A.size() != P.size())
				continue;
			bool flag = true;
			for (int i = 0; flag && i < P.size(); ++i)
			{
				flag &= A[i].first == P[i].first;
				flag &= A[i].second == P[i].second || A[i].second < P[i].second &&
					P[i].second >= 3;
			}
			result += flag;
		}
		return result;
	}
};