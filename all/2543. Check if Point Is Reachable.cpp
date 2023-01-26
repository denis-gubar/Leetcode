class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        int x = targetX, y = targetY;
        while(x % 2 == 0)
            x /= 2;
        while (y % 2 == 0)
            y /= 2;
        return gcd(x, y) == 1;
    }
};