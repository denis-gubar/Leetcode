class Solution {
public:
	int numberOfDays(int Y, int M) {
		vector<int> months{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int result = months[M - 1];
		if (M == 2 && Y % 4 == 0 && (Y % 100 != 0 || Y % 400 == 0))
			++result;
		return result;
	}
};