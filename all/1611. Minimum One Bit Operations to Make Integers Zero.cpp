class Solution {
public:
	int minimumOneBitOperations(int num) {
		num ^= num >> 16;
		num ^= num >> 8;
		num ^= num >> 4;
		num ^= num >> 2;
		num ^= num >> 1;
		return num;
	}
};