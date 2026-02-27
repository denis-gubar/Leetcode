class Solution {
public:
	struct Trie
	{
		Trie(): count(0)
		{

		}
		int add(string const& s)
		{
			Trie* node = this;
			int const delta = s[0] - 'a';
			for (char x : s)
			{
				char c = ((x - 'a') - delta + 26) % 26 + 'a';
				if (node->children.find(c) == node->children.end())
					node->children[c] = new Trie();
				node = node->children[c];
			}
			return ++node->count;
		}
		unordered_map<char, Trie*> children;
		int count;
	};

    long long countPairs(vector<string>& words) {
        long long result = 0;
        int const N = words.size();
		Trie T;
		for (string const& w : words)
			result += T.add(w) - 1;
        return result;
    }
};
