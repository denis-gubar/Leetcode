class Solution {
public:
    int countDigits(int num) {
        int result = 0;
        int N = num;
        while (num > 0)
        {
            int x = num % 10;
            num /= 10;
            if (x > 0 && N % x == 0)
                ++result;
        }
        return result;
    }
};
