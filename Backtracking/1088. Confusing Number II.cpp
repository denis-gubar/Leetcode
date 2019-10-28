class Solution {
public:
	int confusingNumberII(int N) {
		int result = 0;
		vector<int> results{ 0,0,1,4,6,8,26,40,40,115,226,226,391,878,1196,1440,4266,6126,6126,16670,30976,30976,52746,118186,155626,202426,545726,779876,779876 };
		vector<int> r5{ 1,1,3,7,9,11,34,49,49,134,249,249,421,924,1249,1499,4374,6249,6249,16874,31249,31249,53124,118749,156249,203124,546874,781249,781249 };
		vector<int> A{ 0, 1, 6, 8, 9 };
		vector<int> power(10);
		power[0] = 1;
		for (int x = 1; x < 10; ++x)
			power[x] = power[x - 1] * 5;
		int startX = 0;
		if (N < 550'000'000)
		{
			int n = 2;
			int k = 0;
			while (n <= N && n < 1'000'000'000)
			{
				result = results[k];
				startX = r5[k];
				++k;
				n *= 2;
			}
		}
		else
		{
			vector<int> results{ 779876,779877,935976,1170126,1170126,1170127,1326226,1560377,1716476,1950627 };
			vector<int> r5{ 781249,781250,937499,1171874,1171874,1171875,1328124,1562500,1718749,1953124 };
			int n = 550'000'000;
			int k = 0;
			while (n <= N && n <= 1'000'000'000)
			{
				result = results[k];
				startX = r5[k];
				++k;
				n += 50'000'000;
			}
		}
		for (int x = startX + 1; x < power[9]; ++x)
		{
			int n = x;
			vector<int>	digits;
			for (int k = 0; k < 9; ++k)
			{
				digits.push_back(A[n % 5]);
				n /= 5;
			}
			long long d = 0;
			for (int k = 8; k >= 0; --k)
				d = d * 10 + digits[k];
			vector<int> newDigits(digits);
			while (!newDigits.empty() && newDigits.back() == 0)
				newDigits.pop_back();
			if (newDigits.empty())
				newDigits.push_back(0);
			long long nd = 0;
			for (int& z : newDigits)
			{
				if (z == 6 || z == 9)
					z = 15 - z;
				nd = nd * 10 + z;
			}
			if (d > N)
			{
				break;
			}				
			if (d != nd)
				++result;
		}
		return result;
	}
};