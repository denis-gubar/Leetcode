class StreamChecker {
public:
	struct Trie
	{
		unordered_map<char, Trie*> children;
		void add(string const& s)
		{
			Trie* node = this;
			for (int i = s.size() - 1; i >= 0; --i)
			{
				char const& c = s[i];
				if (node->children.find(c) == node->children.end())
					node->children[c] = new Trie();
				node = node->children[c];
			}
			if (node->children.find('$') == node->children.end())
				node->children['$'] = new Trie();
		}
		bool search(string const& s)
		{
			Trie* node = this;
			for (int i = s.size() - 1; i >= 0; --i)
			{
				char const& c = s[i];                
				if (node->children.find(c) == node->children.end())
					return false;
				node = node->children[c];
                if (node->children.find('$') != node->children.end())
                    return true;
			}
			return false;
		}
	};
	Trie* trie;
	string stream;
	StreamChecker(vector<string>& words) {
		trie = new Trie();
		for (string const& w : words)
		{
			trie->add(w);
		}
	}

	bool query(char letter) {
		stream += letter;
		return trie->search(stream);
	}
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */