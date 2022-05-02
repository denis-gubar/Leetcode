class Solution {
public:
    int countEven(int num) {
        int result = 0;
        for (int x = 1; x <= num; ++x)
        {
            int sum = 0;
            int k = x;
            while (k > 0)
            {
                sum += k % 10;
                k /= 10;
            }
            if (sum % 2 == 0)
                ++result;
        }
        return result;
    }
};
