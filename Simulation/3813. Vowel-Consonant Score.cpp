class Solution {
public:
    int vowelConsonantScore(string s) {
        int result = 0;
        string vowels = "aeiou";
        int V = 0, C = 0;
        for (char c : s)
            if ('a' <= c && c <= 'z')
            {
                if (vowels.find(c) != string::npos)
                    ++V;
                else
                    ++C;
            }
        if (C > 0)
            result = V / C;
        return result;
    }
};
