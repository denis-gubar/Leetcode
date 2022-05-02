class Solution {
public:
    bool isDecomposable(string s) {
        s += '$';
        int N = s.size();
        char prev = '^';
        int count = 0;
        int specialCount = 0;
        for (char c : s)
        {
            if (c == prev)
                ++count;
            else
            {
                count %= 3;
                if (count == 1)
                    return false;
                if (count == 2)
                    ++specialCount;
                count = 1;
                prev = c;
            }
        }
        return specialCount == 1;
    }
};
