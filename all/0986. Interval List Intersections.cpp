/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
	vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
		vector<Interval> result;
		vector<pair<int, int>> M;
		for (auto a : A)
		{
			M.push_back({ a.start, -1 });
			M.push_back({ a.end, 1 });
		}
		for (auto b : B)
		{
			M.push_back({ b.start, -1 });
			M.push_back({ b.end, 1 });
		}
		int balance = 0;
		sort(M.begin(), M.end());
		vector<int> P;
		for (auto m : M)
		{
			balance -= m.second;
			if (balance == 2)
			{
				if (P.empty())
					P.push_back(m.first);
				else
				{
					P.push_back(m.first);
					result.push_back(Interval(P[0], P[1]));
					P.clear();
				}
			}
			else
			{
				if (!P.empty())
				{
					P.push_back(m.first);
					result.push_back(Interval(P[0], P[1]));
					P.clear();
				}
			}
		}
		return result;
	}
};