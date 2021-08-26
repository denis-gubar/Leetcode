class Solution {
public:
	bool checkZeroOnes(string s) {		
		auto calc = [&s](char t)
		{
			int z = 0, x = 0;
			for (char c : s)
			{
				if (c == t)
					++x;
				else
					x = 0;
				z = max(z, x);
			}
			return z;
		};
		return calc('1') > calc('0');
	}
};