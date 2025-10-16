class Solution {
public:
    int distributeCandies(int n, int limit) {
        int result = 0;
        for (int i = 0; i <= limit && i <= n; ++i)
            for (int j = 0; j <= limit && i + j <= n; ++j)
                for (int k = 0; k <= limit; ++k)
                    result += i + j + k == n;
        return result;
    }
};
