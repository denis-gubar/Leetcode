class Solution {
public:
	int subtractProductAndSum(int n) {
		vector<int> digits;
		while (n)
		{
			digits.push_back(n % 10);
			n /= 10;
		}
		return accumulate(digits.begin(), digits.end(), 1, multiplies<int>()) -
			accumulate(digits.begin(), digits.end(), 0);
	}
};