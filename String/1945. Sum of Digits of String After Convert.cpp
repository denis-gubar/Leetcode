class Solution {
public:
	int getLucky(string s, int k) {
		int result = 0;
		for (int c : s)
		{
			int z = c - 'a' + 1;
			result += z / 10;
			result += z % 10;
		}
		while (k > 1)
		{
			int newResult = 0;
			while (result > 0)
			{
				newResult += result % 10;
				result /= 10;
			}
			--k;
            result = newResult;
		}
		return result;
	}
};