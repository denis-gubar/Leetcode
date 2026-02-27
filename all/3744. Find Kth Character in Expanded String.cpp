class Solution {
public:
    char kthCharacter(string s, long long k) {
        int length = 0;
        for (char c : s)
            if (c == ' ')
            {
                if (k == 0)
                    return c;
                --k, length = 0;
            }
            else
            {
                if (k <= length)
                    return c;
                ++length, k -= length;
            }
        return '$';
    }
};
