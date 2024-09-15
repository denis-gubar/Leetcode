class Solution {
public:
    int minSteps(int n) {
        int result = 0;
        for(int x = 2; x * x <= n; ++x)
            if (n % x == 0)
                while(n % x == 0)
                {
                    result += x;
                    n /= x;
                }
        if (n > 1)
            result += n;
        return result;
    }
};