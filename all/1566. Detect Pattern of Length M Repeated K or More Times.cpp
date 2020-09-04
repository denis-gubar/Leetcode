class Solution {
public:
	bool containsPattern(vector<int>& arr, int m, int k) {
		int N = arr.size();
		for (int start = 0; start + m * k <= N; ++start)
		{
			bool flag = true;
			for (int i = 1; i < k; ++i)
				for (int j = 0; j < m; ++j)
					flag &= arr[start + j] == arr[start + i * m + j];
			if (flag)
				return true;
		}
		return false;
	}
};