int DATA[100000][27];
int SIZE;

struct AlphabetTrie
{
	AlphabetTrie()
	{
		clear();
	}
	void clear()
	{
		SIZE = 1;
		memset(DATA, 0, sizeof(DATA));
	}
	void add(const string& word, int wordNumber)
	{
		int node = 1;
		for (int i = word.size() - 1; i >= 0; --i)
		{
			if (!DATA[node][word[i] - 'a'])
				++SIZE, DATA[node][word[i] - 'a'] = SIZE;
			node = DATA[node][word[i] - 'a'];
		}
		DATA[node][26] = wordNumber + 100000;
	}
	static bool isPalindrome(const string& word, int start, int end)
	{
		while (start < end)
		{
			if (word[start] != word[end])
				return false;
			++start, --end;
		}
		return true;
	}
	vector<vector<int>> search(const string& word, int wordNumber)
	{
		vector<vector<int>> result;
		int node = 1;
		for (int i = 0; i < word.size(); ++i)
		{
			if (DATA[node][26] && isPalindrome(word, i, word.size() - 1))
			{
				int otherWordNumber = DATA[node][26] - 100000;
				if (otherWordNumber != wordNumber)
					result.push_back({ wordNumber, otherWordNumber });
			}
			if (!DATA[node][word[i] - 'a'])
				return result;
			node = DATA[node][word[i] - 'a'];
		}
		if (DATA[node][26])
		{
			int otherWordNumber = DATA[node][26] - 100000;
			if (otherWordNumber != wordNumber)
				result.push_back({ wordNumber, otherWordNumber });
		}
		return result;
	}
};

class Solution {
public:
	vector<vector<int>> calc(vector<string>& words)
	{
		vector<vector<int>> result;
		AlphabetTrie trie;
		for (int i = 0; i < words.size(); ++i)
			trie.add(words[i], i);
		for (int i = 0; i < words.size(); ++i)
		{
			auto searchResult = trie.search(words[i], i);
			copy(searchResult.begin(), searchResult.end(), back_inserter(result));
		}
		return result;
	}
	vector<vector<int>> palindromePairs(vector<string>& words) {
		vector<vector<int>> result{calc(words)};
		for (string& word : words)
			reverse(word.begin(), word.end());
		auto reversed = calc(words);
		for (auto& r : reversed)
			reverse(r.begin(), r.end());
		copy(reversed.begin(), reversed.end(), back_inserter(result));
		sort(result.begin(), result.end());
		result.erase(unique(result.begin(), result.end()), result.end());
		return result;
	}
};