// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
	int rand2()
	{
		int result = rand7();
		while (result > 6)
			result = rand7();
		return result % 2;
	}
	int rand5()
	{
		int result = rand7();
		while (result > 5)
			result = rand7();
		return result;
	}
	int rand10() {
		return rand2() * 5 + rand5();
	}
};