class Solution {
public:
    int lastRemaining(int N) {
        int L = 1, R = N, T = 2;
        while (L < R)
        {
            R -= (R - L + T / 2) % T;
            L += T / 2;
            if (L == R)
                break;
            T += T;
            R -= T / 2;
            L += (R - L) % T;
            T += T;
        }
        return L;
    }
};
