class Solution {
public:
	void duplicateZeros(vector<int>& arr) {
		int N = arr.size();
		int prefix = 0, newN = 0;
		for (int i = 0; newN < N; ++i)
			++prefix, newN += 1 + (arr[i] == 0);
		int pos = newN - 1;
		for (int i = prefix - 1; i >= 0; --i)
		{
			if (pos < N)
				arr[pos] = arr[i];
			--pos;
			if (!arr[i])
			{
				arr[pos] = 0;
				--pos;
			}
		}
	}
};