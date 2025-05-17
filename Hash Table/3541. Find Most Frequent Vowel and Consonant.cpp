class Solution {
public:
    int maxFreqSum(string s) {
        int result = 0;
        string const vowels{ "aeiou" };
        vector<int> M(128);
        for (char c : s)
            ++M[c];
        int V = 0, C = 0;
        for (char c = 'a'; c <= 'z'; ++c)
            if (vowels.find(c) == string::npos)
                C = max(C, M[c]);
            else
                V = max(V, M[c]);
        return V + C;
    }
};
