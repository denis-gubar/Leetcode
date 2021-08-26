class Solution {
public:
	string convertToTitle(int n) {
		string result;
		if (n < 27)
		{
			result += (n - 1) + 'A';
			return result;
		}
		result += convertToTitle((n - 1) / 26);
		result += convertToTitle((n - 1) % 26 + 1);
		return result;
	}
};