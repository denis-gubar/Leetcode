class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2)
        {
            string t;
            int const N = s.size();
            for (int i = 1; i < N; ++i)
                t += ((s[i - 1] - '0') + (s[i] - '0')) % 10 + '0';
            s = move(t);
        }
        return s[0] == s[1];
    }
};
