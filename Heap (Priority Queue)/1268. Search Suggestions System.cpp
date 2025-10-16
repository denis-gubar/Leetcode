static vector<string> words;
class Solution {
public:
	struct Trie
	{
		Trie()
		{
		}
		void add(int i)
		{
			Trie* node = this;
			for (char c : words[i])
			{
				if (node->children.find(c) == node->children.end())
					node->children[c] = new Trie();
				node = node->children[c];
				if (node->A.size() < 3)
					node->A.push_back(i);
			}
			node->children['#'] = new Trie();
		}
		unordered_map<char, Trie*> children;
		vector<int> A;
	};
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
		words = products;
		sort(words.begin(), words.end());
		Trie T;
		int const P = products.size(), N = searchWord.size();
		for (int i = 0; i < P; ++i)
			T.add(i);
		vector<vector<string>> result(N);
		Trie* node = &T;
		for (int i = 0; i < N; ++i)
		{
			char const c = searchWord[i];
			if (node->children.find(c) == node->children.end())
				break;
			node = node->children[c];
			for (int j : node->A)
				result[i].push_back(words[j]);
		}
		return result;
    }
};
