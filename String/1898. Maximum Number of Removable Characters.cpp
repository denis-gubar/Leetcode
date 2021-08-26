class Solution {
public:
	int maximumRemovals(string s, string p, vector<int>& removable) {
		int N = s.size();
		int a = 0, b = removable.size() + 1;
		vector<int> A(N, 1 << 30);
		for (int i = 0; i < removable.size(); ++i)
			A[removable[i]] = i;
		auto check = [&s, &p, &A](int x)
		{
			int pPos = 0;
			for (int i = 0; i < s.size(); ++i)
				if (A[i] >= x && s[i] == p[pPos])
				{
					++pPos;
					if (pPos == p.size())
						return true;
				}			
			return false;
		};
		while (a + 1 < b)
		{
			int m = (a + b) / 2;
			if (check(m))
				a = m;
			else
				b = m;
		}
		return a;
	}
};