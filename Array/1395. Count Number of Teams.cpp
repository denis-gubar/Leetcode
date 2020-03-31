class Solution {
public:
	int numTeams(vector<int>& rating) {
		int result = 0;
		int N = rating.size();
		for (int i = 0; i < N; ++i)
			for (int j = i + 1; j < N; ++j)
				for (int k = j + 1; k < N; ++k)
					result += rating[i] < rating[j] && rating[j] < rating[k] ||
					rating[i] > rating[j] && rating[j] > rating[k];
		return result;
	}
};