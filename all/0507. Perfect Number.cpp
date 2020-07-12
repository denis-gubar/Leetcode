class Solution {
public:
	bool checkPerfectNumber(int num) {
        if (num == 0)
            return false;
		int sum = 0;
		for (int x = 1; x * x <= num; ++x)
			if (num % x == 0)
            {
				sum += x;
                if (x * x < num)
                    sum += num / x;
            }
		return sum == 2 * num;
	}
};