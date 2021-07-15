class Solution {
public:
	int countTriples(int n) {
		int result = 0;
		for (int a = 1; a <= n; ++a)
			for (int b = 1; b <= n; ++b)
			{
				int c = sqrt(1.0 * a * a + b * b + 0.1);
				if (c * c == a * a + b * b && c <= n)
					++result;					
			}
		return result;
	}
};