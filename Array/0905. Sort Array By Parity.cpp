class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		vector<int> result(A);
		sort(result.begin(), result.end(), [](int a, int b)
		{
			return a % 2 < b % 2;
		});
		return result;
	}
};