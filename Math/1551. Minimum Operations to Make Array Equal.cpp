class Solution {
public:
	int minOperations(int n) {
		int result = 0;
		for (int a = 0, b = n - 1; a < b; ++a, --b)
			result += b - a;
		return result;
	}
};