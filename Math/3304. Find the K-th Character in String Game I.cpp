class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        for (int i = 0; i < k; ++i)
        {
            string ns = s;
            for (char c : s)
                ns += c == 'z' ? 'a' : (c + 1);
            s = ns;
            if (s.size() > k)
                break;
        }
        return s[k - 1];
    }
};
