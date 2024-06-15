class Solution {
public:
	struct Trie
	{
		Trie(int b = 1 << 20, int i = -1) : best_length(b), index(i)
		{

		}
		int best_length;
		int index;
		unordered_map<char, Trie*> children;
		void add(string const& word, int ind)
		{
			Trie* node = this;
			int N = word.size();
			if (node->best_length > N)
				node->best_length = N, node->index = ind;
			for (int i = N - 1; i >= 0; --i)
			{
				char const& c = word[i];
				if (node->children.find(c) == node->children.end())
				{
					node->children[c] = new Trie(N, ind);
					node = node->children[c];
				}
				else
				{
					node = node->children[c];
					if (node->best_length > N)
						node->best_length = N, node->index = ind;
				}
			}
		}
		int search(string const& word)
		{
			Trie* node = this;
			int N = word.size();
			for (int i = N - 1; i >= 0; --i)
			{
				char const& c = word[i];
				if (node->children.find(c) == node->children.end())
					break;
				node = node->children[c];
			}
			return node->index;
		}
	};
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
		int N = wordsContainer.size();
        int Q = wordsQuery.size();
        vector<int> result(Q);
		Trie trie;
		for (int i = 0; i < N; ++i)
			trie.add(wordsContainer[i], i);
        for (int q = 0; q < Q; ++q)
			result[q] = trie.search(wordsQuery[q]);
        return result;
    }
};
