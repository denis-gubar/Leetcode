class Solution {
public:
    int countCommas(int N) {
        int result = 0;
        for (int i = 1; i <= N; ++i)
        {
            if (i >= 1'000)
                ++result;
        }
        return result;
    }
};
