class Solution {
public:
	bool isLeap(int year)
	{
		return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
	}
	int daysBetweenDates(string date1, string date2) {
		vector<int> months{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		int result = 0;
		int year1 = atoi(date1.substr(0, 4).c_str());
		int year2 = atoi(date2.substr(0, 4).c_str());
		int month1 = atoi(date1.substr(5, 2).c_str());
		int month2 = atoi(date2.substr(5, 2).c_str());
		int day1 = atoi(date1.substr(8, 2).c_str());
		int day2 = atoi(date2.substr(8, 2).c_str());
		if (vector<int>{ year1, month1, day1 } > vector<int>{year2, month2, day2})
		{
			swap(year1, year2);
			swap(month1, month2);
			swap(day1, day2);
		}
		while (vector<int>{ year1, month1, day1 } != vector<int>{year2, month2, day2})
		{
			months[1] = 28 + isLeap(year1);
			if (vector<int>{ year1, month1 } < vector<int>{year2, month2})
			{
				result += months[month1 - 1] - day1 + 1;
				day1 = 1;
				if (month1 == 12)
					month1 = 1, ++year1;
				else
					++month1;
			}
            else
            {
                result += day2 - day1;
                day1 = day2;
            }
		}
		return result;
	}
};