class Solution {
public:
	int getSum(int a, int b) {
		int result = a ^ b;
		int shift = (a & b) << 1;
		while (shift)
		{
			int newShift = (result & shift) << 1;
			result ^= shift;
			shift = newShift;
		}
		return result;
	}
};