// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		int a = 0, b = n;
		while (a + 1 < b)
		{
			int m = a + (b - a) / 2;
			if (isBadVersion(m))
				b = m;
			else
				a = m;
		}
		return b;
	}
};