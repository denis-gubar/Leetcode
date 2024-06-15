class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = 0, X = x;
        while (x > 0)
        {
            sum += x % 10;
            x /= 10;
        }
        if (X % sum == 0)
            return sum;
        return -1;
    }
};
