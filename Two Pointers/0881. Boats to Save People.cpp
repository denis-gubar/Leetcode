class Solution {
public:
	int numRescueBoats(vector<int>& people, int limit) {
		int result = 0;
		sort(people.begin(), people.end());
		int a = 0, b = people.size() - 1;
		while (a <= b)
		{
			if (people[a] + people[b] > limit)
			{
				++result;  --b;
			}
			else
			{
				++result; ++a; --b;
			}
		}
		return result;
	}
};