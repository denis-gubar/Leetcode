class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) return true;
        int a = 0, b = num;
        while(a + 1 < b)
        {
            long long m = (0LL + a + b) / 2;
            if (m * m == num) return true;
            if (m * m > num)
                b = m;
            else
                a = m;
        }
        return false;
    }
};