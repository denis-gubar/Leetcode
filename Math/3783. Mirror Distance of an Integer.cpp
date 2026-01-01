class Solution {
public:
    int mirrorDistance(int n) {
        int x = n, r = 0;
        while (x > 0)
        {
            r = r * 10 + x % 10;
            x /= 10;
        }
        return abs(n - r);
    }
};
