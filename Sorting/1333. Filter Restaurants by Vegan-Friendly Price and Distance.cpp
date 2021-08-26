class Solution {
public:
	vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
		vector<vector<int>> A;
		for (vector<int>& r : restaurants)
			if ((r[2] || !veganFriendly) &&
				r[3] <= maxPrice &&
				r[4] <= maxDistance)
				A.push_back({ -r[1], -r[0] });
		sort(A.begin(), A.end());
		vector<int> result;
		for (vector<int>& row : A)
			result.push_back(-row[1]);
		return result;
	}
};