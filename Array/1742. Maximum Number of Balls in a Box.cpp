class Solution {
public:
	int countBalls(int lowLimit, int highLimit) {
		vector<int> A(100);
		for (int x = lowLimit; x <= highLimit; ++x)
		{
			int n = x;
			int sum = 0;
			while (n)
			{
				sum += n % 10;
				n /= 10;
			}
			++A[sum];
		}
		return *max_element(A.begin(), A.end());
	}
};