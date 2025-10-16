class Solution {
public:
    int calc(int x, int y)
    {
        int prev = 0;
        int result = 0;
        while (true)
        {
            ++prev;
            x -= prev;
            if (x < 0)
                break;
            ++result;
            ++prev;
            y -= prev;
            if (y < 0)
                break;
            ++result;
        }
        return result;
    }
    int maxHeightOfTriangle(int red, int blue) {
        return max(calc(red, blue), calc(blue, red));
    }
};
