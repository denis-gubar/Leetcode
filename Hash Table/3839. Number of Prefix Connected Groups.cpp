class Solution {
public:
	struct Trie
	{
		Trie()
		{
		}
		bool add(string const& s, int K)
		{
			Trie* node = this;
			for(int i = 0; i < K; ++i)
			{
				char const& c = s[i];
				if (node->children.find(c) == node->children.end())
					node->children[c] = new Trie();
				node = node->children[c];
			}
			return (++node->count == 2);				
		}
		unordered_map<char, Trie*> children;
		int count = 0;
	};
	int prefixConnected(vector<string>& words, int K) {
        int result = 0;
        int const N = words.size();
		Trie T;
		for (int i = 0; i < N; ++i)
			if (words[i].size() >= K)
				result += T.add(words[i], K);
        return result;
    }
};
