class Solution {
public:
    int minChanges(int n, int k) {
        if ((n & k) != k)
            return -1;
        int x = n ^ k;
        int result = 0;
        while (x)
            ++result, x &= x - 1;
        return result;
    }
};
