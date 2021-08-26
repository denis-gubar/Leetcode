class Solution {
public:
	int scheduleCourse(vector<vector<int>>& courses) {
		sort(courses.begin(), courses.end(), [](vector<int> const& a, vector<int> const& b)
			{
				return a[1] < b[1];
			});
		int total = 0;
		priority_queue<int> Q;
		for(vector<int> const& c : courses)
		{
			int const& duration = c[0];
			int const& lastDay = c[1];
			if (total + duration <= lastDay)
			{
				Q.push(duration);
				total += duration;
				continue;
			}
			if (!Q.empty() && Q.top() > duration && total - Q.top() + duration <= lastDay)
			{
				total -= Q.top();
				Q.pop();
				Q.push(duration);
				total += duration;
			}
		}
		return Q.size();
	}
};