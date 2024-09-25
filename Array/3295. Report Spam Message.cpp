class Solution {
public:
	struct Trie
	{
		unordered_map<char, Trie*> children;
		void add(string const& word)
		{
			Trie* node = this;
			for (char c : word)
			{
				if (node->children.find(c) == node->children.end())
					node->children[c] = new Trie();
				node = node->children[c];
			}
			if (node->children.find('#') == node->children.end())
				node->children['#'] = new Trie();
		}
		bool search(string const& word)
		{
			Trie* node = this;
			for (char c : word)
			{
				if (node->children.find(c) == node->children.end())
					return false;
				node = node->children[c];
			}
			return node->children.find('#') != node->children.end();
		}
	};
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
		Trie T;
		for (string const& s : bannedWords)
			T.add(s);
		int result = 0;
		for (string const& s : message)
		{
			result += T.search(s);
			if (result == 2)
				return true;
		}
		return false;
    }
};
