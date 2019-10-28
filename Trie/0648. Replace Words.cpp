struct Trie
{
	Trie() : children(vector<Trie*>(26)), isWord(false) {}
	~Trie()
	{
		for (Trie* child : children)
			delete child;
	}

	void add(const string& s)
	{
		Trie* node = this;
		for (int i : s)
			if (node->children[i - 'a'])
				node = node->children[i - 'a'];
			else
				node = node->children[i - 'a'] = new Trie();
		node->isWord = true;
	}

	string searchPrefix(const string& s)
	{
		Trie* node = this;
		for (int i = 0; i < s.size(); ++i)
			if (node->children[s[i] - 'a'])
			{
				node = node->children[s[i] - 'a'];
				if (node->isWord)
					return s.substr(0, i + 1);
			}
			else
				return s;
		return s;
	}

	vector<Trie*> children;
	bool isWord;
};

class Solution {
public:
	string replaceWords(vector<string>& dict, const string& sentence) {
		Trie trie;
		for (const string& d : dict)
			trie.add(d);
		string result;
		istringstream s(sentence);
		while (!s.eof())
		{
			string t;
			s >> t;
			if (!result.empty())
				result += ' ';
			result += trie.searchPrefix(t);
		}
		return result;
	}
};