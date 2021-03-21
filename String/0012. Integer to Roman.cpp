class Solution {
public:
	string intToRoman(int num) {
		vector<int> digital{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 
				10, 20, 30, 40, 50, 60, 70, 80, 90, 
				100, 200, 300, 400, 500, 600, 700, 800, 900,
				1000, 2000, 3000,
		};
		vector<string> roman{ "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
				"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
				"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
				"M", "MM", "MMM"
		};
		string result;
		int power = 1;
		while (num > 0)
		{
			int x = num % 10;
			if (x != 0)
			{
				int pos = lower_bound(digital.begin(), digital.end(), x * power) - digital.begin();
				result = roman[pos] + result;
			}
			num /= 10;
			power *= 10;
		}
		return result;
	}
};