class Solution {
public:
	struct Trie
	{
		unordered_map<char, Trie*> children;
		Trie(bool isRoot = false)
		{
			if (isRoot)
				children['#'] = this;
		}
		int add(string const& word)
		{
			Trie* node = this;
			for (char c : word)
			{
				if (node->children.find('#') == node->children.end())
					return -1;
				if (node->children.find(c) == node->children.end())
					node->children[c] = new Trie();
				node = node->children[c];
			}
			if (node->children.find('#') == node->children.end())
				node->children['#'] = new Trie();
			return word.size();
		}
	};
	string longestWord(vector<string>& words) {
		sort(words.begin(), words.end());
		int const N = words.size();
		int result = -1, best = -1;
		Trie T(true);
		for (int i = 0; i < N; ++i)
			if (int x = T.add(words[i]); best < x)
				best = x, result = i;
		if (result == -1)
			return "";
		return words[result];
    }
};
