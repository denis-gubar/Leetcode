static int W[26];
class Solution {
public:
    int countDivisibleSubstrings(string word) {
        int result = 0;
        string letters{ "ab cde fgh ijk lmn opq rst uvw xyz" };
        int weight = 1;
        for (char c : letters)
            if (c == ' ')
                ++weight;
            else
                W[c - 'a'] = weight;
        int const N = word.size();
        for (int i = 0; i < N; ++i)
        {
            int sum = 0;
            for (int j = i; j < N; ++j)
                sum += W[word[j] - 'a'], result += sum % (j - i + 1) == 0;
        }
        return result;
    }
};
