class WordDistance {
public:
    WordDistance(vector<string>& wordsDict): N(wordsDict.size()) {
        for (int i = 0; i < N; ++i)
            M[wordsDict[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        auto const& A = M[word1];
        auto const& B = M[word2];
        int a = 0, b = 0;
        int result = N;
        int x = 0, y = 0;
        while (a < A.size() || b < B.size())
        {
            if (a < A.size())
                x = A[a];
            if (b < B.size())
                y = B[b];
            result = min(result, abs(x - y));
            if (a < A.size() && x < y)
                ++a;
            else if (b < B.size() && x > y)
                ++b;
            else
                break;
        }
        return result;
    }
    int N;
    unordered_map<string, vector<int>> M;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
