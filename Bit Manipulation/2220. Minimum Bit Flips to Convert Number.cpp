class Solution {
public:
    int minBitFlips(int start, int goal) {
        int result = 0;
        int x = start ^ goal;
        while (x)
        {
            x &= x - 1;
            ++result;
        }
        return result;
    }
};
