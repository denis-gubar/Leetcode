class Solution {
public:
    string compressedString(string word) {
        string result;
        word += '$';
        int N = word.size();
        result.reserve(N * 2);
        char prev = '^';
        int count = 0;
        for (char c : word)
        {
            if (prev == c)
            {
                if (++count == 10)
                    result += '9', result += c, count = 1;
            }
            else
            {
                if (count > 0)
                    result += '0' + count, result += prev;
                prev = c, count = 1;
            }
        }
        return result;
    }
};
