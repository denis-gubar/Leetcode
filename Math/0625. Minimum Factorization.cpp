class Solution {
public:
    int smallestFactorization(int num) {
        if (num < 10)
            return num;
        long long result = 0;
        array const primes{ 2, 3, 5, 7 };
        unordered_map<int, int> M;
        for (int x : primes)
            while (num % x == 0)
                ++M[x], num /= x;
        if (num > 1)
            return 0;
        long long base = 1;
        while (M[3] > 1)
            M[3] -=2, result += base * 9, base *= 10;
        while (M[2] > 2)
            M[2] -= 3, result += base * 8, base *= 10;
        while (M[7] > 0)
            --M[7], result += base * 7, base *= 10;
        while (M[2] > 0 && M[3] > 0)
            --M[2], --M[3], result += base * 6, base *= 10;
        while (M[5] > 0)
            --M[5], result += base * 5, base *= 10;
        while (M[2] > 1)
            M[2] -= 2, result += base * 4, base *= 10;
        while (M[3] > 0)
            --M[3], result += base * 3, base *= 10;
        while (M[2] > 0)
            --M[2], result += base * 2, base *= 10;
        if (static_cast<int>(result) != result)
            return 0;
        return result;
    }
};
