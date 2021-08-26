class Solution {
public:
	int romanToInt( string s ) {
		int result = 0;
		vector<int> di = { 900, 1000, 400, 500, 90, 100, 40, 50, 9, 10, 4, 5, 1 };
		vector<string> ds = { "CM", "M", "CD", "D", "XC", "C", "XL", "L", "IX", "X", "IV", "V", "I" };
		while (!s.empty())
		{
			for (int i = 0; i < ds.size(); ++i)
				if (s.find( ds[i] ) !=  string::npos)
				{
					s.replace(s.find(ds[i]), ds[i].size(), string());
					result += di[i];
				}
		}

		return result;
	}
};