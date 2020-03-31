class Solution {
public:
	int findLucky(vector<int>& arr) {
		int result = -1;
		vector<int> A(501);
		for (int a : arr)
			++A[a];
		for (int i = 1; i < 501; ++i)
			if (A[i] == i)
				result = i;
		return result;
	}
};