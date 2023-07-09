class Solution {
public:
    vector<int> evenOddBit(int N) {
        vector<int> result(2);
        vector<int> digits;
        while (N > 0)
        {
            digits.push_back(N % 2);
            N /= 2;
        }
        for (int i = 0; i < digits.size(); ++i)
            if (digits[i] == 1)
                ++result[i % 2];
        return result;
    }
};
