class Solution {
public:
	vector<vector<int>> indexPairs(string text, vector<string>& words) {
		vector<vector<int>> result;
		sort(words.begin(), words.end(), [](string const& a, string const& b)
			{
				return a.size() < b.size();
			});
		for (int i = 0; i < text.size(); ++i)
			for (string const& word : words)
				if (text.substr(i, word.size()) == word)
                    result.push_back({ i, i + static_cast<int>(word.size()) - 1 });
		return result;
	}
};