class Solution {
public:
	string maxValue(string n, int x) {
		string result(n);
		int N = n.size();
		char c = '0' + x;
		if (n[0] == '-')
		{
			result += '9';
			++result.back();
			for (int i = 1; i <= N; ++i)
				if (result[i] > c)
				{
					result.insert(result.begin() + i, c);
					result.pop_back();
					return result;
				}
		}
		result += '0';
		--result.back();
		for (int i = 0; i <= N; ++i)
			if (result[i] < c)
			{
				result.insert(result.begin() + i, c);
				result.pop_back();
				return result;
			}
		return result;
	}
};