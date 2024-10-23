class ValidWordAbbr {
public:
    string calc(string const& word)
    {
        int const N = word.size();
        if (N < 3)
            return word;
        return word[0] + to_string(N - 2) + word.back();
    }
    unordered_map<string, unordered_set<string>> M;
    ValidWordAbbr(vector<string> const& dictionary) {
        for (string const& word : dictionary)
            M[calc(word)].insert(word);
    }
    
    bool isUnique(string const& word) {
        string s = calc(word);
        return M.find(s) == M.end() || M[s].size() == 1 && *M[s].begin() == word;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */
