class Solution {
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		int N = list1.size(), M = list2.size();
		for (int sum = 0; sum + 2 <= N + M; ++sum)
		{
			vector<string> result;
			for (int i = max(sum - M + 1, 0); i <= min(sum, N - 1); ++i)
			{
				int j = sum - i;
				if (list1[i] == list2[j])
					result.push_back(list1[i]);
			}
			if (!result.empty())
				return result;
		}
		return {};
	}
};