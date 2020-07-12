class Solution {
public:
	int distributeCandies(vector<int>& candies) {
		return min<int>(candies.size() / 2, unordered_set<int>(candies.begin(), candies.end()).size());
	}
};