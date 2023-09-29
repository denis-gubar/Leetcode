class Solution {
public:
    string calc(string s)
    {
        char a = min(s[0], s[2]);
        char b = min(s[1], s[3]);
        char c = max(s[0], s[2]);
        char d = max(s[1], s[3]);
        string result;
        result += a;
        result += b;
        result += c;
        result += d;
        return result;
    }
    bool canBeEqual(string s1, string s2) {
        return calc(s1) == calc(s2);
    }
};
