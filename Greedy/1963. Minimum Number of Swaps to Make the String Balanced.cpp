class Solution {
public:
	int minSwaps(string s) {
		int N = s.size();
		int result = 0;
		int balance = 0;
		for (char c : s)
		{
			if (c == '[')
				++balance;
			else
				--balance;
			if (balance == -1)
				++result, balance = 1;
		}
		return result;
	}
};