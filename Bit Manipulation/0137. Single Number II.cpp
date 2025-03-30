class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        //  a  b  x na nb
        //  0  0  0  0  0
        //  0  1  0  0  1
        //  1  0  0  1  0
        //  0  0  1  0  1
        //  0  1  1  1  0
        //  1  0  1  0  0
        for (int x : nums)
        {
            int na = (a & ~b & ~x) | (~a & b & x);
            int nb = ~a & (b ^ x);
            a = na, b = nb;
        }
        return b;
    }
};
