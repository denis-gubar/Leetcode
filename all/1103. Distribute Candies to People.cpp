class Solution {
public:
	vector<int> distributeCandies(int candies, int num_people) {
		vector<int> result(num_people);
		int x = 1, pos = 0;
		while (candies)
		{
			int give = min(candies, x);
			candies -= give;
			result[pos] += give;
			pos = (pos + 1) % num_people;
			++x;
		}
		return result;
	}
};