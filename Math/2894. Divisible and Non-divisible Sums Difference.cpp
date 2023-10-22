class Solution {
public:
    int differenceOfSums(int n, int m) {
        long long result = 0;
        for (int x = 1; x <= n; ++x)
            if (x % m != 0)
                result += x;
        for (int x = 1; x <= n; ++x)
            if (x % m == 0)
                result -= x;
        return result;
    }
};
