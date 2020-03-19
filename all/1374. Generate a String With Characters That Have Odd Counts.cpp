class Solution {
public:
	string generateTheString(int n) {
		string result(n, 'a');
		if (n % 2 == 0)
			result = string(n - 1, 'a') + 'b';
		return result;
	}
};