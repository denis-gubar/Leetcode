class Solution {
public:
    bool validDigit(int N, int X) {
        vector<int> digits;
        while (N > 0 || digits.empty())
        {
            int D = N % 10;
            digits.push_back(D);
            N /= 10;
        }
        if (digits.back() == X)
            return false;
        digits.pop_back();
        for (int D : digits)
            if (D == X)
                return true;
        return false;
    }
};
