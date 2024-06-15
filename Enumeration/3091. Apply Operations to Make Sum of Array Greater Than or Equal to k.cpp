class Solution {
public:
    int minOperations(int k) {
        int result = k - 1;
        for (int i = 1; i < k; ++i)
            result = min(result, i - 2 + (k + i - 1) / i);
        return result;
    }
};
