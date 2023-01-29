class Solution {
public:
	class WordDictionary {
	public:
		/** Initialize your data structure here. */
		WordDictionary() : children(vector<WordDictionary*>(26)), isWord(false) {}
		~WordDictionary()
		{
			for (WordDictionary* child : children)
				delete child;
		}

		/** Adds a word into the data structure. */
		void addWord(string const& word) {
			WordDictionary* node = this;
			for (int i : word)
				if (node->children[i - 'a'])
					node = node->children[i - 'a'];
				else
					node = node->children[i - 'a'] = new WordDictionary;
			node->isWord = true;
		}

		/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
		vector<int> search(string_view word) {
			vector<int> result;
			WordDictionary* node = this;
			for (int i = 0; i < word.size(); ++i)
			{
				if (node->isWord)
					result.push_back(i);
				if (!node->children[word[i] - 'a'])
					return result;				
				node = node->children[word[i] - 'a'];
			}
			if (node->isWord)
				result.push_back(word.size());
			return result;
		}
		vector<WordDictionary*> children;
		bool isWord;
	};
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		vector<string> result;
		WordDictionary WD;
		for (string const& word : words)
			WD.addWord(word);
		vector<bool> F(31);
		for (string const& word : words)
		{
			int N = word.size();
			F.assign(N + 1, false);
			F[0] = true;
			for (int offset = 0; offset < N; ++offset)
				if (F[offset])
				{
					vector<int> A = WD.search(string_view(&word.c_str()[offset], N - offset));
					for (int x : A)
						if (x < N)
							F[offset + x] = true;
				}
			if (F[N])
				result.push_back(word);
		}
		return result;
    }
};
