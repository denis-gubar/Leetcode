class Solution {
public:
    int consecutiveNumbersSum( int N ) {
        int result = 0;
        for (int n = 1; N - (n - 1) * n / 2 > 0; ++n)
            result += (N - (n - 1) * n / 2) % n == 0;
        return result;
    }
};