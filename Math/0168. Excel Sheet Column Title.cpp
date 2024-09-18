class Solution {
public:
	string convertToTitle(int n) {
		string result;
		if (n > 26)
		    result += convertToTitle((n - 1) / 26);
		result += (n - 1) % 26 + 'A';
		return result;
	}
};