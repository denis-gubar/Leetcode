class Solution {
public:
    int findComplement(int num) {
        long long x = 2;
        while(x <= num)
            x <<= 1;
        return x - 1 - num;
    }
};