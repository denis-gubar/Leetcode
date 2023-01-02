class Solution {
public:
    int pivotInteger(int n) {
        int result = -1;
        int total = n * (n + 1) / 2;
        for (int i = 1; i <= n; ++i)
        {
            int sum = i * (i + 1) / 2;
            if (sum == total)
                return i;
            total -= i;
        }
        return result;
    }
};
