class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int result = words.size(), a = -result, b = -result;
        for(int i = 0; i < words.size(); ++i)
            if (words[i] == word1)
            {
                result = min(result, i - b);
                a = i;
            }
            else if (words[i] == word2)
            {
                result = min(result, i - a);
                b = i;
            }
        return result;
    }
};