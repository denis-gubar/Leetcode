class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int deltaX = abs(fx - sx);
        int deltaY = abs(fy - sy);
        int delta = max(deltaX, deltaY);
        if (t == 1)
            return delta == 1;
        return delta <= t;
    }
};
