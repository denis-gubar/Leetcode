class Solution {
public:
    bool calc(int x)
    {
        vector<int> digits;
        while (x > 0)
        {
            digits.push_back(x % 10);
            x /= 10;
        }
        int n = digits.size();
        if (n % 2 == 1)
            return false;
        int sum = 0;
        for (int i = 0; i < n / 2; ++i)
        {
            sum += digits[i];
            sum -= digits[digits.size() - 1 - i];
        }
        return sum == 0;
    }
    int countSymmetricIntegers(int low, int high) {
        int result = 0;
        for (int x = low; x <= high; ++x)
            result += calc(x);
        return result;
    }
};
