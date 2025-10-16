class Solution {
public:
	struct Trie
	{
		Trie* zero;
		Trie* one;
		Trie() : zero(nullptr), one(nullptr)
		{
		}
		void add(string_view const& s)
		{
			Trie* node = this;
			for (char c : s)
				if (c == '0')
				{
					if (!node->zero)
						node->zero = new Trie();
					node = node->zero;
				}
				else
				{
					if (!node->one)
						node->one = new Trie();
					node = node->one;
				}
		}
		bool find(string const& s)
		{
			Trie* node = this;
			for (char c : s)
				if (c == '0')
				{
					if (!node->zero)
						return false;
					node = node->zero;
				}
				else
				{
					if (!node->one)
						return false;
					node = node->one;
				}
			return true;
		}
	};
	bool queryString(string S, int N) {
		if (S.size() < N)
			return false;
		Trie trie;
		int k = N, height = 0;
		while (k)
		{
			++height;
			k /= 2;
		}
		for (int i = 0; i < S.size(); ++i)
			trie.add(string_view(&S[i], min<int>(S.size() - i, height)));
		string n{ "0" };
		for (int x = 0; x < N; ++x)
		{
			int pos = n.size() - 1;
			while (pos >= 0 && n[pos] == '1')
			{
				n[pos] = '0';
				--pos;
			}
			if (pos < 0)
				n.insert(n.begin(), '1');
			else
				n[pos] = '1';
			if (!trie.find(n))
				return false;
		}
		return true;
	}
};