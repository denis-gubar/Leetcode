class Solution {
public:
	int hIndex(vector<int>& citations) {
		int N = citations.size();
		if (!N || citations[0] >= N) return N;
		int a = 0, b = N;
		while (a + 1 < b)
		{
			int m = (a + b) / 2;
			if (citations[N - m] >= m)
				a = m;
			else
				b = m;
		}
		return a;
	}
};