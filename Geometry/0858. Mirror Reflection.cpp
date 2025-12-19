class Solution {
public:
    int mirrorReflection(int p, int q) {
        int dir = 1;
        int x = 0, y = 0;
        while(true)
        {
            if (x == p && y == 0)
                return 0;
            if (x == p && y == p)
                return 1;
            if (x == 0 && y == p)
                return 2;            
            y += dir * q;
            if (y > p)
                y = p - (y - p), dir = -dir;
            if (y < 0)
                y = -y, dir = -dir;
            x = p - x;
        }
        return -1;
    }
};