class MagicDictionary {
public:
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> const& dictionary)  {
        A = vector<vector<string>>(101);
        for (string const& w : dictionary)
            A[w.size()].push_back(w);
    }
    
    bool search(string const& searchWord) {
        int const N = searchWord.size();
        for (string const& w : A[N])
        {
            int count = 0;
            for (int i = 0; i < N && count < 2; ++i)
                count += searchWord[i] != w[i];
            if (count == 1)
                return true;
        }
        return false;
    }
    vector<vector<string>> A;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
