class Solution {
public:
    int newInteger(int n, long long sum = 0, long long k = 1) {
        if (n == 0) return sum;
        return newInteger(n / 9, sum + n % 9 * k, k * 10);
    }
};