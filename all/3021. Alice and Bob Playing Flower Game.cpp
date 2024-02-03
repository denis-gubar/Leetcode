class Solution {
public:
    long long flowerGame(long long n, long long m) {
        long long result = 0;
        result += (n / 2) * ((m + 1) / 2);
        result += ((n + 1) / 2) * (m / 2);
        return result;
    }
};
