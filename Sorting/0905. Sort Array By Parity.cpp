class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		partition(A.begin(), A.end(), [](int x)
			{
				return x % 2 == 0;
			});
		return A;
	}
};