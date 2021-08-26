class WordFilter {
public:
	struct Trie
	{
		unordered_map<string, int> suffixes;
		unordered_map<char, Trie*> children;
		Trie()
		{
		}
		void add(string s, int x)
		{
			Trie* node = this;
			string r(s);
			reverse(r.begin(), r.end());
			for (char c : s)
			{
				if (node->children[c] == nullptr)
					node->children[c] = new Trie();
				node = node->children[c];				
				string t(r);
				while (!t.empty())
				{
					node->suffixes[t] = x;
					t.pop_back();
				}
			}
		}
	};
	WordFilter(vector<string>& words) {
		for (int i = 0; i < words.size(); ++i)
			trie.add(words[i], i);
	}

	int f(string prefix, string suffix) {
		Trie* node = &trie;
		reverse(suffix.begin(), suffix.end());
		for (char c : prefix)
		{
			if (!node)
				break;
			node = node->children[c];
		}
		if (node)
		{
			auto it = node->suffixes.find(suffix);
			if (it != node->suffixes.end())
				return it->second;
		}
		return -1;
	}
	Trie trie;
};



/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */