class Solution {
public:
	int sumOfDigits(vector<int>& A) {
		int result = 0;
		int x = *min_element(A.begin(), A.end());
		while (x)
		{
			result += x % 10;
			x /= 10;
		}
		return (result + 1) % 2;
	}
};