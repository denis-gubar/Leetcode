class Solution {
public:
	int calc(int x)
	{
		int result = 0;
		while (x)
		{
			x &= x - 1;
			++result;
		}
		return result;
	}
	vector<string> readBinaryWatch(int num) {
		vector<string> result;
		for (int hh = 0; hh < 12; ++hh)
			for (int mm = 0, h = calc(hh); mm < 60; ++mm)
				if (h + calc(mm) == num)
					result.push_back(to_string(hh) + ":" + to_string(100 + mm).substr(1));
		return result;
	}
};