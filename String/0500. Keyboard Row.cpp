class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		vector<string> rows{ "qwertyuiop", "asdfghjkl", "zxcvbnm" };
		vector<string> result;
		for (string const& word : words)
		{
			int a = 3, b = -1, x = -1;
			for (char c : word)
				for (int i = 0; i < 3; ++i)
					if (rows[i].find(c) != string::npos)
					{
						x = i;
						a = min(a, x);
						b = max(b, x);
					}
			if (a == b)
				result.push_back(word);
		}
		return result;
	}
};