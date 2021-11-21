class Solution {
public:
	int minMovesToSeat(vector<int>& seats, vector<int>& students) {
		int result = 0;
		sort(seats.begin(), seats.end());
		sort(students.begin(), students.end());
		int N = seats.size();
		for (int i = 0; i < N; ++i)
			result += abs(students[i] - seats[i]);
		return result;
	}
};