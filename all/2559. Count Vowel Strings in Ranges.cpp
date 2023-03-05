class Solution {
public:
    bool isVowel(char c)
    {
        return "aeiou"s.find(c) != string::npos;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int N = words.size();
        int Q = queries.size();
        vector<int> result(Q);
        vector<int> A(N + 1);
        for (int i = 0; i < N; ++i)
            A[i + 1] = A[i] + (isVowel(words[i][0]) && isVowel(words[i].back()));
        for (int i = 0; i < Q; ++i)
        {
            int const& L = queries[i][0];
            int const& R = queries[i][1];
            result[i] = A[R + 1] - A[L];
        }
        return result;
    }
};
