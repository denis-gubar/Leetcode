class Solution {
public:
    int minAllOneMultiple(int K) {
        int x = 0;
        for (int result = 1; result <= K; ++result)
        {
            x = (x * 10 + 1) % K;
            if (x == 0)
                return result;
        }
        return -1;
    }
};
