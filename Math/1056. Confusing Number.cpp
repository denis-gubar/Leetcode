class Solution {
public:
	bool confusingNumber(int N) {
		vector<int> to{ 0, 1, -1, -1, -1, -1, 9, -1, 8, 6 };
		int other = 0;
		int x = N;
		while (x)
		{
			int k = to[x % 10];
			if (k < 0)
				return false;
			x /= 10;
			other = other * 10 + k;
		}
		return N != other;
	}
};