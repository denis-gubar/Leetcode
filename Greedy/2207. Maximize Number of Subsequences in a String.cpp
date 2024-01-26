class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long result = 0;
        int a = count(text.begin(), text.end(), pattern[0]);
        int c = count(text.begin(), text.end(), pattern[1]), b = c;
        for (char c : text)
        {
            if (c == pattern[1])
                --b;
            if (c == pattern[0])
                result += b;
        }
        result += max(a, c);
        return result;
    }
};
