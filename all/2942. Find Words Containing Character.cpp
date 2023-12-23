class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;
        int N = words.size();
        for (int i = 0; i < N; ++i)
            if (words[i].find(x) != string::npos)
                result.push_back(i);
        return result;
    }
};
