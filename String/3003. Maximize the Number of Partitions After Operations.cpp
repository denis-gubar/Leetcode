static unsigned int masks[10'001];
static unsigned int duplicates[10'001];
static unsigned int F[10'001];
class Solution {
public:
    int maxPartitionsAfterOperations(string s, int K) {
        if (K == 26)
            return 1;
        int const N = s.size();
        unsigned int mask = 0, duplicateMask = 0, current = 1;
        for (int i = 0; i < N; ++i)
        {
            unsigned int x = 1 << (s[i] - 'a');
            duplicateMask |= x & mask;
            mask |= x;
            if (popcount(mask) > K)
            {
                ++current;
                mask = x;
                duplicateMask = 0;
            }
            masks[i] = mask, duplicates[i] = duplicateMask, F[i] = current;
        }
        mask = 0, duplicateMask = 0, current = 0;
        unsigned int result = F[N  - 1];
        for (int i = N - 1; i >= 0; --i)
        {
            unsigned int x = 1 << (s[i] - 'a');
            duplicateMask |= x & mask;
            mask |= x;
            int bitCount = popcount(mask);
            if (bitCount > K)
            {
                ++current;
                mask = x;
                duplicateMask = 0;
                bitCount = 1;
            }
            if (bitCount == K)
            {
                if ((x & duplicateMask) > 0 && (x & duplicates[i]) > 0 &&
                    popcount(masks[i]) == K &&
                    (masks[i] | mask) != (1 << 26) - 1)
                    result = max(result, F[i] + current + 2);
                else if (duplicateMask)
                    result = max(result, F[i] + current + 1);
            }
        }
        return result;
    }
};
