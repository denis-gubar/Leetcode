class Solution {
public:
	bool isHappy(int n) {
		set<int> S;
		S.insert(n);
		while (true)
		{
			int nextN = 0;
			while (n)
			{
				nextN += (n % 10) * (n % 10);
				n /= 10;
			}
			n = nextN;
			if (n == 1)
				return true;
			if (S.find(n) != S.end())
				return false;
			S.insert(n);
		}
	}
};