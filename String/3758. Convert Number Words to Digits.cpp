class Solution {
public:
	struct Trie
	{
		Trie(): d('#')
		{

		}
		void add(string const& s, char d)
		{
			Trie* node = this;
			for (char c : s)
			{
				if (node->children.find(c) == node->children.end())
					node->children[c] = new Trie();
				node = node->children[c];
			}
			node->d = d;
		}
		pair<int, char> search(string const& s, int pos)
		{
			Trie* node = this;
			int const N = s.size();
			for (int i = pos; i < N; ++i)
			{
				char const c = s[i];
				if (node->children.find(c) == node->children.end())
					return { pos + 1, '#' };
				node = node->children[c];
				if (node->d != '#')
					return { i + 1, node->d };
			}
			return { pos + 1, '#' };
		}
		char d;
		unordered_map<char, Trie*> children;
	};
	string convertNumber(string s) {
		Trie T;
		array const D = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
		for (int i = 0; i < 10; ++i)
			T.add(D[i], '0' + i);
		string result;
		int const N = s.size();
		for (int pos = 0; pos < N; )
		{
			pair<int, char> P = T.search(s, pos);
			pos = P.first;
			if (P.second != '#')
				result += P.second;
		}
		return result;        
    }
};
