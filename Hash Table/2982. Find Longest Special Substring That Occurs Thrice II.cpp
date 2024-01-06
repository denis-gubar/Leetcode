class Solution {
public:
	int maximumLength(string s) {
		s += 'z' + 1;
		int N = s.size();
		int a = 0, b = N;
		vector<vector<int>> A(27);
		char prev = 'z' + 1;
		int count = 0;
		for (int i = 0; i < N; ++i)
		{
			if (s[i] == prev)
				++count;
			else
			{
				A[prev - 'a'].push_back(count);
				prev = s[i];
				count = 1;
			}
		}
		for (int i = 0; i < 26; ++i)
			sort(A[i].begin(), A[i].end(), greater{});
		auto calc = [&A](int length)
			{
				for (int i = 0; i < 26; ++i)
				{
					int count = 0;
					for (int x : A[i])
					{
						if (x < length)
							break;
						count += x - length + 1;
					}
					if (count >= 3)
						return true;
				}
				return false;
			};
		while (a + 1 < b)
		{
			int m = (a + b) / 2;
			if (calc(m))
				a = m;
			else
				b = m;
		}
		if (a == 0)
			a = -1;
		return a;
	}
};


