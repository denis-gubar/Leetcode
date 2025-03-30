class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int a_xor_b = 0, a = 0;
        for (unsigned int x : nums)
            a_xor_b ^= x;
        unsigned int bit = a_xor_b & (a_xor_b ^ (a_xor_b - 1));
        for (unsigned int x : nums)
            if ((bit & x) > 0)
                a ^= x;
        return { static_cast<int>(a), static_cast<int>(a_xor_b ^ a) };
    }
};
