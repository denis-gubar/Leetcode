class Solution {
public:
	int countStudents(vector<int>& students, vector<int>& sandwiches) {
		int period = 0;
		int pos = 0;
		deque<int> A(students.begin(), students.end());
		while (!A.empty())
		{
			if (A.front() == sandwiches[pos])
			{
				A.pop_front();
				++pos;
				period = 0;
			}
			else
			{
				++period;
				A.push_back(A.front());
				A.pop_front();
			}
			if (period == 1'000)
				break;
		}
		return A.size();
	}
};