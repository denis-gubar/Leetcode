class Solution {
public:
    long long countCommas(long long N) {
        long long result = 0;
        if (N < 1'000)
            return result;
        if (N < 1'000'000)
            return N - 1'000 + 1;
        result += 1'000'000 - 1'000;
        if (N < 1'000'000'000)
            return result + 2 * (N - 1'000'000 + 1);
        result += 2 * (1'000'000'000 - 1'000'000);
        if (N < 1'000'000'000'000LL)
            return result + 3LL * (N - 1'000'000'000 + 1);
        result += 3LL * (1'000'000'000'000LL - 1'000'000'000);
        if (N < 1'000'000'000'000'000LL)
            return result + 4 * (N - 1'000'000'000'000LL + 1);
        return result + 4 * (1'000'000'000'000'000LL - 1'000'000'000'000LL) + 5;
    }
};
