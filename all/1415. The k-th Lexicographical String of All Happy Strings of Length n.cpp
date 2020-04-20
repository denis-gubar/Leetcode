class Solution {
public:
	string getHappyString(int n, int k) {		
		vector<int> F{ 1 };
		for (int i = 0; i < 10; ++i)
			F.push_back(F.back() * 3);
		for (int x = 0; x < F[n]; ++x)
		{
			vector<int> digits(n);
			int z = x;
			bool isGood = true;
			for (int j = 0; j < n; ++j)
			{
				digits[j] = z % 3;
				z /= 3;
				if (j && digits[j] == digits[j - 1])
				{
					isGood = false;
					break;
				}
			}
			if (isGood)
				--k;
			if (k == 0)
			{
				reverse(digits.begin(), digits.end());
				string result;
				for (int d : digits)
					result += d + 'a';
				return result;
			}
		}
		return {};
	}
};