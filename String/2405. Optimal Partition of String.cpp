class Solution {
public:
    int partitionString(string s) {
        int result = 1;
        int M = 0;
        for (char c : s)
        {
            int x = c - 'a';
            if (M & (1 << x))
            {
                M = 0;
                ++result;
            }
            M |= 1 << x;
        }
        return result;
    }
};
