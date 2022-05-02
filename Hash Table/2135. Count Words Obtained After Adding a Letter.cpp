class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int result = 0;
        int N = startWords.size(), M = targetWords.size();
        vector<int> S(N);
        unordered_map<int, int> F;
        for (int i = 0; i < N; ++i)
            for (char c : startWords[i])
                S[i] |= 1 << (c - 'a');
        for (int i = 0; i < M; ++i)
        {
            int T = 0;
            for (char c : targetWords[i])
                T |= 1 << (c - 'a');
            ++F[T];
        }
        for (int i = 0; i < N; ++i)
        {
            int hash = S[i];
            for(int k = 0; k < 26; ++k)
                if ((hash & (1 << k)) == 0)
                {
                    int newHash = hash | (1 << k);
                    auto it = F.find(newHash);
                    if (it != F.end())
                    {
                        result += it->second;
                        F.erase(it);
                    }
                }
        }
        return result;
    }
};
