class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
		int a = s1.size(), b = s2.size();
		vector<int> Prev(a + 1), Cur(a + 1);
		for (int i = 1; i <= a; ++i)
			Cur[i] = Cur[i - 1] + s1[i - 1];
		for (int i = 0; i < b; ++i)
		{
			Cur.swap(Prev);
			Cur[0] = Prev[0] + s2[i];
			for (int j = 1; j <= a; ++j)
			{
				Cur[j] = min(Cur[j - 1] + s1[j - 1], Prev[j] + s2[i]);
				if (s1[j - 1] == s2[i])
					Cur[j] = min(Cur[j], Prev[j - 1]);
				else
					Cur[j] = min(Cur[j], Prev[j - 1] + s1[j - 1] + s2[i]);
			}
		}
		return Cur[a];
    }
};
