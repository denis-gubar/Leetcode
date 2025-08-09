class Solution {
public:
    bool checkDivisibility(int N) {
        vector<int> digits;
        int S = 0;
        int P = 1;
        int const X = N;
        while (N > 0)
        {
            int D = N % 10;
            S += D;
            P *= D;
            N /= 10;
        }
        return X % (S + P) == 0;
    }
};
