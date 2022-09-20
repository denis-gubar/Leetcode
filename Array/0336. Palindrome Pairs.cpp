static bool isPalindrome(const string& word, int start, int end)
{
    while (start < end)
    {
        if (word[start] != word[end])
            return false;
        ++start, --end;
    }
    return true;
}
struct AlphabetTrie
{   
    AlphabetTrie* children[26];
    int pos;
    vector<int> indices;
    AlphabetTrie(): pos(-1)
    {
        memset(children, 0, sizeof(children));
    }
    void add(string const& word, int wordNumber)
    {
        AlphabetTrie* node = this;
        for (int i = word.size() - 1; i >= 0; --i)
        {
            if (isPalindrome(word, 0, i))
                node->indices.push_back(wordNumber);
            if (!node->children[word[i] - 'a'])
                node->children[word[i] - 'a'] = new AlphabetTrie();
            node = node->children[word[i] - 'a'];
        }
        node->pos = wordNumber;
        node->indices.push_back(wordNumber);
    }    
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        int N = words.size();
        AlphabetTrie root{};
        for (int i = 0; i < N; ++i)
            root.add(words[i], i);
        for (int i = 0; i < N; ++i)
        {
            AlphabetTrie* node = &root;
            for (int j = 0; j < words[i].size() && node != nullptr; ++j)
            {
                if (node->pos != -1 && node->pos != i && isPalindrome(words[i], j, words[i].size() - 1))
                    result.push_back({ i, node->pos });
                node = node->children[words[i][j] - 'a'];
            }
            if (!node)
                continue;
            for (int pos : node->indices)
                if (i != pos)
                    result.push_back({ i, pos });
        }        
        return result;
    }
};
