class Solution{
public:
	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> result;
		for (int n = left; n <= right; ++n)
		{
			int flag = true;
			int x = n;
			while(x)
			{
				int r = x % 10;
				if (r == 0 || n % r != 0)
				{
					flag = false;
					break;
				}
				x /= 10;
			}
			if (flag)
				result.push_back(n);
		}
		return result;
	}
};