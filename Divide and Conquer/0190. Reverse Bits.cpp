class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		bitset<32> A(n), B;
		for (int i = 0; i < 32; ++i)
			B[i] = A[31 - i];
		return B.to_ulong();
	}
};