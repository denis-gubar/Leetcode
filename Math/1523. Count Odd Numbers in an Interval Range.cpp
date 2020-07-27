class Solution {
public:
	int countOdds(int low, int high) {
		int result = (high - low) / 2 + max(high % 2, low % 2);
		return result;
	}
};