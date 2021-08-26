// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
	int search(const ArrayReader& reader, int target) {
		int a = 0;
		int A = reader.get(a);
		if (A > target) return -1;
		if (A == target) return 0;
		int b = 1 << 15;
		while (a + 1 < b)
		{
			int m = (a + b) / 2;
			int M = reader.get(m);
			if (M == target) return m;
			if (M > target)
				b = m;
			else
				a = m;
		}
		return -1;
	}
};