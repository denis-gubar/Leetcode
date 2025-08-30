class Solution {
public:
    int gcdOfOddEvenSums(int N) {
        int sumOdd = 0, sumEven = 0;
        for (int i = 0; i < N; ++i)
        {
            sumOdd += 2 * i + 1;
            sumEven += 2 * i + 2;
        }
        return gcd(sumOdd, sumEven);
    }
};
