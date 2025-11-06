class Solution {
public:
    string maxSumOfSquares(int N, int sum) {
        if (N * 9 < sum)
            return {};
        string result(N, '0');
        for (int i = 0; i < N; ++i)
        {
            if (sum == 0)
                break;
            int delta = min(sum, 9);
            result[i] = delta + '0';
            sum -= delta;
        }
        return result;
    }
};
