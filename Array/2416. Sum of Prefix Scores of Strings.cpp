struct AlphabetTrie
{
    AlphabetTrie* children[26];
    int count;
    AlphabetTrie() : count(0)
    {
        memset(children, 0, sizeof(children));
    }
    void add(string const& word)
    {
        AlphabetTrie* node = this;
        for(int i = 0; i < word.size(); ++i)
        {            
            if (!node->children[word[i] - 'a'])
                node->children[word[i] - 'a'] = new AlphabetTrie();
            node = node->children[word[i] - 'a'];
            ++node->count;
        }
    }
    int search(string const& word)
    {
        int result = 0;
        AlphabetTrie* node = this;
        for (int i = 0; i < word.size(); ++i)
        {
            node = node->children[word[i] - 'a'];
            result += node->count;
        }
        return result;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int N = words.size();
        vector<int> result(N);
        AlphabetTrie trie{};
        for (int i = 0; i < N; ++i)
            trie.add(words[i]);
        for (int i = 0; i < N; ++i)
            result[i] = trie.search(words[i]);
        return result;
    }
};
