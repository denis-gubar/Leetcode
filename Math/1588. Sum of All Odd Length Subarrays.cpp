class Solution {
public:
	int sumOddLengthSubarrays(vector<int>& arr) {
		int N = arr.size();
		long long result = 0;		
		for (int start = 0; start < N; ++start)
		{
			int current = arr[start];
			result += current;
			for (int length = 3; start + length <= N; length += 2)
			{
				current += arr[start + length - 2] + arr[start + length - 1];
				result += current;
			}
        }
		return result;
	}
};