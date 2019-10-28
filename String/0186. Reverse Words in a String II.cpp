class Solution {
public:
	void reverseWords(vector<char>& str) {
		int N = str.size();
		for (int a = 0, b = N - 1; a < b; ++a, --b)
			swap(str[a], str[b]);
		for (int head = 0; head < N; ++head)
		{
			int tail = head;
			for (; tail < N && str[tail] != ' '; ++tail);
			for (int a = head, b = tail - 1; a < b; ++a, --b)
				swap(str[a], str[b]);
			head = tail;
		}
	}
};