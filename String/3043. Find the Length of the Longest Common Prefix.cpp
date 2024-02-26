class Solution {
public:
	struct Trie
	{
		unordered_map<char, Trie*> children;
		void add(string const& s)
		{
			Trie* node = this;
			for (char c : s)
			{
				if (node->children.find(c) == node->children.end())
					node->children[c] = new Trie();
				node = node->children[c];
			}
			if (node->children.find('$') == node->children.end())
				node->children['$'] = new Trie();
		}
		int search(string const& s)
		{
			int result = 0;
			Trie* node = this;
			for (char c : s)
			{
				if (node->children.find(c) == node->children.end())
					break;
				node = node->children[c];
				++result;
			}
			return result;
		}
	};
	int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
		int result = 0;
		Trie trie;
		for (int x : arr1)
			trie.add(to_string(x));
		for (int x : arr2)
			result = max(result, trie.search(to_string(x)));
		return result;
	}
};
