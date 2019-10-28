class Solution {
public:
	int missingNumber(vector<int>& arr) {
		int N = arr.size();
		int delta = arr[N - 1] - arr[0];
		for (int i = 1; i < N; ++i)
			if (arr[0] + delta / N * i != arr[i])
				return arr[0] + delta / N * i;
		return arr[0];
	}
};