class Solution {
public:
	int findKthPositive(vector<int>& arr, int k) {
		int result = 0;
		vector<int>	A(3000);
		for (int x : arr)
			A[x] = 1;
		for (int i = 1, z = 0; z < k; ++i)
			if (!A[i])
				result = i, ++z;
		return result;
	}
};