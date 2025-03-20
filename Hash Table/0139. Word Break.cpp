static bool F[301];
static string s;
class Solution {
public:
	struct Trie
	{
		Trie()
		{
		}
		void add(string const& s)
		{
			Trie* node = this;
			for (char c : s)
			{
				if (node->children.find(c) == node->children.end())
					node->children[c] = new Trie();
				node = node->children[c];
			}
			node->children['#'] = new Trie();
		}
		void search(int pos)
		{
			Trie* node = this;
			int const N = s.size();
			for ( ; pos < N; ++pos)
			{
				char const c = s[pos];
				if (node->children.find(c) == node->children.end())
					return;
				node = node->children[c];
				if (node->children.find('#') != node->children.end())
					F[pos + 1] = true;
			}
		}
		unordered_map<char, Trie*> children;
	};
    bool wordBreak(string s, vector<string>& wordDict) {
		::s = s;
		int const N = s.size();
		memset(F, 0, sizeof(F));
		F[0] = true;
		Trie root;
		for (string const& w : wordDict)
			root.add(w);
		for (int i = 0; i < N; ++i)
			if (F[i])
				root.search(i);
		return F[N];
    }
};
