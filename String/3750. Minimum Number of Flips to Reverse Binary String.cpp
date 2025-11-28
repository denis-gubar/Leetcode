class Solution {
public:
    int minimumFlips(int n) {
        bitset<30> N(n);
        int x = n, r = 0;
        while (x > 0)
        {
            r = r * 2 + x % 2;
            x /= 2;
        }
        bitset<30> R(r);
        int result = 0;
        for (int i = 0; i < 30; ++i)
            result += N[i] != R[i];
        return result;
    }
};
