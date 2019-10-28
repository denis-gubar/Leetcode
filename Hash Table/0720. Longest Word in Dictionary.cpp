class Solution {
public:
	string longestWord(vector<string>& words) {
		string result;
		sort(words.begin(), words.end());
		set<string> S;
		for (const string& word : words)
			if (word.size() == 1 || S.find(word.substr(0, word.size() - 1)) != S.end())
			{
				if (result.size() < word.size())
					result = word;
				S.insert(word);
			}
		return result;
	}
};