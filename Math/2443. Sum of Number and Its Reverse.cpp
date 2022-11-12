class Solution {
public:
    int calc(int x)
    {
        int result = 0;
        while (x > 0)
        {
            result = result * 10 + x % 10;
            x /= 10;
        }        
        return result;
    }
    bool sumOfNumberAndReverse(int num) {
        if (num == 0) return true;
        for (int x = 1; x < num; ++x)
            if (x + calc(x) == num)
                return true;
        return false;
    }
};
