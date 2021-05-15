class Solution {
public:
	int getMinSwaps(string num, int k) {
		int result = 0;
		int N = num.size();
		string next(num);
		while (k > 0)
		{
			next_permutation(next.begin(), next.end());
			--k;
		}
		int last = 0;
		while (true)
		{
			while (last < N && num[last] == next[last])
				++last;
			if (last == N)
				break;
			int pos = next.find(num[last], last);
			while (pos > last)
			{
				swap(next[pos - 1], next[pos]);
				++result;
				--pos;
			}
			++last;
		}
		return result;
	}
};