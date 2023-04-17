class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int result = 0;
        int delta = min(numOnes, k);
        k -= delta;
        result += delta;
        delta = min(numZeros, k);
        k -= delta;
        delta = min(numNegOnes, k);
        result -= delta;
        return result;
    }
};
