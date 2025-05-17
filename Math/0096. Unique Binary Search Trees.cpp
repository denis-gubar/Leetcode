class Solution {
public:
    int numTrees(int N) {
        int result = 1;
        for (int i = 2; i <= N; ++i)
            result = 1LL * result * (4 * i - 2) / (i + 1);
        return result;
    }
};
