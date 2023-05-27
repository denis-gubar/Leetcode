class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int N = word1.size(), M = word2.size();
        int pos1 = 0, pos2 = 0;
        while (pos1 < N || pos2 < M)
        {
            if (pos1 < N)
                result += word1[pos1], ++pos1;
            if (pos2 < M)
                result += word2[pos2], ++pos2;
        }
        return result;
    }
};
