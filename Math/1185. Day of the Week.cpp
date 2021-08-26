class Solution {
public:
	bool isLeap(int year)
	{
		return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
	}
	string dayOfTheWeek(int day, int month, int year) {
		vector<string> days{ "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
		vector<int> D{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int result = 4;
		int startYear = 1971;
		while (startYear < year)
			result += 1 + isLeap(startYear), ++startYear;
		D[2] += isLeap(year);
		int startMonth = 1;
		while (startMonth < month)
			result += D[startMonth], ++startMonth;
		result += day;
		return days[result % 7];
	}
};