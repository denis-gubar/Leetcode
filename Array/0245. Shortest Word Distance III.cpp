class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        vector<int> A, B;
        int N = wordsDict.size();
        int result = N;
        for (int i = 0; i < N; ++i)
        {
            if (wordsDict[i] == word1)
                A.push_back(i);
            if (wordsDict[i] == word2)
                B.push_back(i);
        }
        int x = 0, y = 0;
        int a = 0, b = 0;
        while (a < A.size() || b < B.size())
        {
            if (a < A.size())
                x = A[a];
            if (b < B.size())
                y = B[b];
            if (x != y)
                result = min(result, abs(x - y));
            if (a < A.size() && x <= y)
                ++a;
            else if (b < B.size() && x >= y)
                ++b;
            else
                break;
        }
        return result;
    }
};
