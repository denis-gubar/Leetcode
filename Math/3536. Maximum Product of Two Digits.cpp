class Solution {
public:
    int maxProduct(int N) {
        int result = 0;
        vector<int> digits;
        while (N > 0)
        {
            digits.push_back(N % 10);
            N /= 10;
        }
        sort(digits.begin(), digits.end());
        int const D = digits.size();
        return digits[D - 2] * digits[D - 1];
    }
};
