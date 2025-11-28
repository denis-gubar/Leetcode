static int F[10];
class Solution {
public:
    string getPermutation(int N, int K) {
        F[0] = 1;
        for(int i = 1; i < 10; ++i)
            F[i] = i * F[i - 1];
        --K;
        string result;
        string digits(N, ' ');
        iota(digits.begin(), digits.end(), '1');
        int i = N - 1;
        while(i >= 0)
        {
            int d = 0;
            if (K > 0)
            {
                d = K / F[i];
                K -= F[i] * d;
            }
            result += digits[d], digits.erase(digits.begin() + d);            
            --i;
        }
        return result;
    }
};