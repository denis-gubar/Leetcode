class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int k = 0; k < 32; ++k)
        {
            uint32_t bit = n & 1;
            n >>= 1;
            result = (result << 1) | bit;
        }
        return result;
    }
};
