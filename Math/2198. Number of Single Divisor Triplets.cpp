class Solution {
public:
    long long singleDivisorTriplet(vector<int>& nums) {
        long long result = 0;
        vector<int> M(101);
        for (int x : nums)
            ++M[x];
        for (short a = 1; a < 101; ++a)
            if (M[a] > 0)
                for (short b = a; b < 101; ++b)
                    if (M[b] > 0)
                        for (short c = b; c < 101; ++c)
                            if (M[c] > 0)
                            {
                                short const sum = a + b + c;
                                short const checkSum = (sum % a == 0) + (sum % b == 0) + (sum % c == 0);
                                if (checkSum != 1)
                                    continue;
                                if (a != b && b != c)
                                    result += 6LL * M[a] * M[b] * M[c];
                                else
                                    result += 3LL * M[b] * (M[b] - 1) * M[sum - 2 * b];
                            }
        return result;
    }
};
