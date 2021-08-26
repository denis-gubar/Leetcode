class Solution {
public:
	string reverseWords(string s) {
		string result;
		vector<string> words{ {} };
		for (char c : s)
		{
			if (c != ' ')
				words.back() += c;
			else
			{
				if (!words.back().empty())
					words.push_back({});
			}
		}
		if (words.back().empty())
			words.pop_back();
		reverse(words.begin(), words.end());
		for (string const& word : words)
			if (result.empty())
				result = word;
			else
			{
				result += ' ';
				result += word;
			}
		return result;
	}
};