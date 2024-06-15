class Solution {
public:
    int numberOfChild(int N, int K) {
        int result = 0;
        int dir = 1;
        for (int i = 0; i < K; ++i)
        {
            result += dir;
            if (result < 0)
                result = 1, dir = 1;
            else if (result == N)
                result = N - 2, dir = -1;
        }
        return result;
    }
};
