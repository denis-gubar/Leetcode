class WordDictionary {
public:
	/** Initialize your data structure here. */
	WordDictionary(): children(vector<WordDictionary*>(26)), isWord(false) {}
	~WordDictionary()
	{
		for (WordDictionary* child : children)
			delete child;
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		WordDictionary* node = this;
		for (int i : word)
			if (node->children[i - 'a'])
				node = node->children[i - 'a'];
			else
				node = node->children[i - 'a'] = new WordDictionary;
		node->isWord = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		WordDictionary* node = this;
		for (int i = 0; i < word.size(); ++i)
		{
			if (word[i] == '.')
			{
				bool result = false;
				for (WordDictionary* child : node->children)
					if (child)
						result |= child->search(word.substr(i + 1));
				return result;
			}
			if (!node->children[word[i] - 'a'])
				return false;
			node = node->children[word[i] - 'a'];
		}
		return node->isWord;
	}
	vector<WordDictionary*> children;
	bool isWord;
};
