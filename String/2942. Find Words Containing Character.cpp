class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int const N = words.size();
        vector<int> result;
        result.reserve(N);
        for (int i = 0; i < N; ++i)
            if (words[i].find(x) != string::npos)
                result.push_back(i);
        return result;
    }
};
