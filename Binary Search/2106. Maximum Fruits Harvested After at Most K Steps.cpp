class Solution {
public:
	int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
		int result = 0;
		int N = fruits.size();
		vector<int> F(200'001), A{ 0 };
        A.reserve(200'002);
		for (int i = 0; i < N; ++i)
		{
			int const& position = fruits[i][0];
			int const& amount = fruits[i][1];
			F[position] = amount;
		}
		partial_sum(F.begin(), F.end(), back_inserter(A));
		for (int left = 0; left <= k && left <= startPos; ++left)
		{
			int right = min(200'000, max(startPos, startPos - left + (k - left)));
			result = max(result, A[right + 1] - A[startPos - left]);            
		}
        for (int right = 0; startPos + right <= 200'000 && right <= k; ++right)
		{
			int left = max(0, min(startPos, startPos + right - (k - right)));
			result = max(result, A[startPos + right + 1] - A[left]);            
		}
		return result;
	}
};