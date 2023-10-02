class Trie {
public:
    Trie(): count(0) {
        
    }
    
    void insert(string word) {
        Trie* node = this;
        word += '#';
        ++node->count;
        for (char c : word)
        {
            if (node->children.find(c) == node->children.end())
                node->children[c] = new Trie();
            node = node->children[c];
            ++node->count;
        }
        word.pop_back();
    }
    
    int countWordsEqualTo(string word) {
        Trie* node = this;
        word += '#';
        for (char c : word)
        {
            if (node->children.find(c) == node->children.end())
            {
                word.pop_back();
                return 0;
            }
            node = node->children[c];
        }
        word.pop_back();
        return node->count;
    }
    
    int countWordsStartingWith(string prefix) {
        Trie* node = this;
        for (char c : prefix)
        {
            if (node->children.find(c) == node->children.end())
                return 0;
            node = node->children[c];
        }
        return node->count;
    }
    
    void erase(string word) {
        Trie* node = this;
        word += '#';
        --node->count;
        for (char c : word)
        {
            node = node->children[c];
            --node->count;
        }
        word.pop_back();
    }
    unordered_map<char, Trie*> children;
    int count;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */
