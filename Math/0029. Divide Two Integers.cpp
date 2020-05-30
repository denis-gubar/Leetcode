class Solution {
public:
	int divide(int dividend, int divisor) {
        if (dividend == divisor)
            return 1;
		if (dividend == numeric_limits<int>::lowest() && divisor == -1)
			return numeric_limits<int>::max();
		if (divisor == numeric_limits<int>::lowest())
			return 0;
		if (dividend > 0)
			dividend = -dividend, divisor = -divisor;
		int sign = -1;
		if (divisor > 0)
			divisor = -divisor, sign = 1;
        if (divisor < dividend)
            return 0;
		int base = divisor;
		int result = -1;
		vector<pair<int, int>> A;
		A.emplace_back(base, result);
		while (numeric_limits<int>::lowest() - base <= base && base + base >= dividend)
		{
			result += result;
			base += base;
			A.emplace_back(base, result);
		}
		A.pop_back();
		while (!A.empty())
		{
			if (base != dividend && numeric_limits<int>::lowest() - base <= A.back().first && base + A.back().first >= dividend)
			{
				result += A.back().second;
				base += A.back().first;
			}
			A.pop_back();
		}
		return sign * result;
	}
};