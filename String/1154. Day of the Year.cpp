class Solution {
public:
	int dayOfYear(string date) {
		int year = atoi(date.substr(0, 4).c_str());
		int month = atoi(date.substr(5, 2).c_str());
		int day = atoi(date.substr(8, 2).c_str());
        cout << year << ' ' << month << ' ' << day << '\n';
		vector<int> M{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
			M[2] = 29;
		int result = 0;
		for (int m = 1; m < month; ++m)
			result += M[m];
		result += day;
		return result;
	}
};