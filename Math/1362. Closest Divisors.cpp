class Solution {
public:
	vector<int> closestDivisors(int num) {
		vector<int> result;
		int num1 = num + 1, num2 = num + 2;
		for (int x = 1; x * x <= num2; ++x)
		{
			if (num1 % x == 0)
			{
				vector<int> newResult{ x, num1 / x };
				if (result.empty() || abs(result[1] - result[0]) >
					abs(newResult[1] - newResult[0]))
					result = newResult;
			}
			if (num2 % x == 0)
			{
				vector<int> newResult{ x, num2 / x };
				if (result.empty() || abs(result[1] - result[0]) >
					abs(newResult[1] - newResult[0]))
					result = newResult;
			}
		}
		return result;
	}
};