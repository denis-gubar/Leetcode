static int result;
class Solution {
public:
	struct Trie
	{
		unordered_map<char, Trie*> children;
		bool isWord;
		Trie* add(string_view s)
		{
			Trie* root = this;
			for (char c : s)
			{
				if (root->children.find(c) == root->children.end())
					root->children[c] = new Trie();
				root = root->children[c];
			}
			result += !root->isWord;
			root->isWord = true;
			return root;
		}
	};
	int equalDigitFrequency(string s) {
		result = 0;
		Trie trie;
        int const N = s.size();
		string_view sw(s);
        for (int i = 0; i < N; ++i)
        {
			Trie* root = &trie;
			int last = i;
			vector<int> M(10);
			for (int j = i; j < N; ++j)
			{
				++M[s[j] - '0'];
				int m = 0;
				for(int d = 0; d < 10; ++d)
					if (M[d])
					{
						if (M[d] == m)
							continue;
						if (m == 0)
							m = M[d];
						else
						{
							m = 0;
							break;
						}
					}
				if (m > 0)
				{
					root = root->add(s.substr(last, j - last + 1));
					last = j + 1;
				}
			}
        }
        return result;
    }
};
