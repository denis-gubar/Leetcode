class Solution {
public:
    int minDistance(string const& word1, string const& word2) {
        int a = word1.size(), b = word2.size();
        int result = 0;
        for (int i = 0; i < word1.size(); ++i)
            result += word1[i] != word2[i];
        return result;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        int N = queries.size(), M = dictionary.size();
        for (int i = 0; i < N; ++i)
        {
            bool found = false;
            for (int j = 0; j < M; ++j)
            {
                if (minDistance(queries[i], dictionary[j]) <= 2)
                {
                    found = true;
                    break;
                }
            }
            if (found)
                result.push_back(queries[i]);
        }
        return result;
    }
};
