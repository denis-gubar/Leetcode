class Solution {
public:
	string to_lower(const string& s)
	{
		string result(s);
		for (char& x : result)
			x = tolower(x);
		return result;
	}
	pair<string, int> removeVowels(const string& s)
	{
		string vowels{"aeiou"};
        int const N = s.size();
		pair<string, int> result{ "", 0 };
        result.first.reserve(N);
		for (char x : s)
			if (vowels.find(x) == string::npos)
				result.first += x;
			else
			{
				++result.second;
				result.first += ' ';
			}
		return result;
	}
	vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
		unordered_set<string> setWordList;
		unordered_map<string, string> lowerWordList;
		map<pair<string, int>, string> noVowelsList;
		for (const string& word : wordlist)
		{
			setWordList.insert(word);
			string s = to_lower(word);
			if (lowerWordList.find(s) == lowerWordList.end())
				lowerWordList[s] = word;
			pair<string, int> p = removeVowels(s);
			if (noVowelsList.find(p) == noVowelsList.end())
				noVowelsList[p] = word;
		}
		vector<string> result;
		for (const string& query : queries)
		{
			if (setWordList.find(query) != setWordList.end())
			{
				result.push_back(query);
				continue;
			}
			string s = to_lower(query);
			if (lowerWordList.find(s) != lowerWordList.end())
			{
				result.push_back(lowerWordList[s]);
				continue;
			}
			pair<string, int> p = removeVowels(s);
			if (noVowelsList.find(p) != noVowelsList.end())
				result.push_back(noVowelsList[p]);
			else
				result.push_back({});
		}
		return result;
	}
};