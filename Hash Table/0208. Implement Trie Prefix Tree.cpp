struct Trie 
{
	Trie(Trie* parentTrie = nullptr) : children(vector<Trie*>(26)), parent(parentTrie) {}

	~Trie()
	{
		for (auto child : children)
			if (child)
				delete child;
	}

	/** Inserts a word into the trie. */
	void insert(const string& word)
	{
		Trie* node = this;
		for (int c : word)
			if (!node->children[c - 'a'])
				node = node->children[c - 'a'] = new Trie(node);
			else
				node = node->children[c - 'a'];
		node->parent->isLastChild[word.back() - 'a'] = 1;
	}

	bool search(const string& word)
	{
		Trie* node = this;
		for (int c : word)
			if (!node->children[c - 'a'])
				return false;
			else
				node = node->children[c - 'a'];
		return node->parent->isLastChild[word.back() - 'a'];
	}

	bool startsWith(const string& prefix)
	{
		Trie* node = this;
		for (int c : prefix)
			if (!node->children[c - 'a'])
				return false;
			else
				node = node->children[c - 'a'];
		return true;
	}

	vector<Trie*> children;
	bitset<26> isLastChild;
	Trie* parent;
};