class Solution {
public:
    int brokenCalc(int X, int Y) {
        int result = 0;
        while (Y > X)
        {
            ++result;
            if (Y % 2 == 1)
                ++Y;
            else
                Y /= 2;
        }
        return result + X - Y;
    }
};