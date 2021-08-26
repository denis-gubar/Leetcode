class Solution {
public:
	int findLengthOfShortestSubarray(vector<int>& arr) {
		int N = arr.size();
		int result = N - 1;
		int current = 1;
		vector<int>	left, right;
		left.push_back(arr[0]);
		for (int i = 1; i < N; ++i)
			if (arr[i] >= arr[i - 1])
				++current, left.push_back(arr[i]);
			else
				break;
		result = min(result, N - current);
		current = 1;
		right.push_back(arr.back());
		for (int i = N - 2; i >= 0; --i)
			if (arr[i] <= arr[i + 1])
				++current, right.push_back(arr[i]);
			else
				break;
		result = min(result, N - current);
		if (result == 0)
			return result;		
		int a = 0, b = 0, R = right.size();
        reverse(right.begin(), right.end());
		while (a < left.size() && b < R)
		{
			while (b < right.size() && left[a] > right[b])
				++b;
			if (b < right.size() && left[a] <= right[b])
				result = min<int>(result, N - (a + 1 + R - b));
			++a;
		}
		return result;
	}
};