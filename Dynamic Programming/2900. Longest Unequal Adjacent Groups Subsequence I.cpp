class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int N, vector<string>& words, vector<int>& groups) {
        vector<string> result;
        for (int start = 0; start < 2; ++start)
        {
            vector<string> S;
            int prev = 1 - start;
            for(int i = 0; i < N; ++i)
                if (groups[i] == prev)
                {
                    S.push_back(words[i]);
                    prev = 1 - prev;
                }
            if (S.size() > result.size())
                result = move(S);
        }
        return result;
    }
};
