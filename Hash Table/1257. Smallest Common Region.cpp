class Solution {
public:
	string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
		int k = 0;
		map<string, int> R;
		for (vector<string> const& region: regions)
			for(string const& r: region)
				if (R.find(r) == R.end())
				{
					R[r] = k;
					++k;
				}
		vector<string> connectivity(k);
		for (vector<string> const& region : regions)
			for (int i = 1; i < region.size(); ++i)
				connectivity[R[region[i]]] = region[0];
		int a = 0;
		string s = region1;
		while (!connectivity[R[s]].empty())
		{
			++a; s = connectivity[R[s]];
		}
		int b = 0;
		s = region2;
		while (!connectivity[R[s]].empty())
		{
			++b; s = connectivity[R[s]];
		}
		string s1 = region1;
		string s2 = region2;
		while (a < b)
		{
			--b; s2 = connectivity[R[s2]];
		}
		while (a > b)
		{
			--a; s1 = connectivity[R[s1]];
		}
		while (s1 != s2)
		{
			s1 = connectivity[R[s1]];
			s2 = connectivity[R[s2]];
		}
		return s1;
	}
};