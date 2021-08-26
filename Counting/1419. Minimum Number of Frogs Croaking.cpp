class Solution {
public:
	int minNumberOfFrogs(string croakOfFrogs) {
		int c = 0, r = 0, o = 0, a = 0, k = 0;
		int result = 0;
		for (char ch : croakOfFrogs)
		{
			switch (ch)
			{
			case 'c':
				++c;
				result = max(result, c);
				break;
			case 'r':
				++r;
				if (r > c) return -1;
				break;
			case 'o':
				++o;
				if (o > r) return -1;
				break;
			case 'a':
				++a;
				if (a > o) return -1;
				break;
			case 'k':
				++k;
				if (k > a) return -1;
				--k, --a, --o, --r, --c;
				break;
			default:
				return -1;
			}
		}
        if (c + r + o + a + k > 0)
            return -1;
		return result;
	}
};