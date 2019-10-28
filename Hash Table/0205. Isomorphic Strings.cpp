class Solution {
public:
	bool isIsomorphic(string s, string t) {
		vector<int> mapping(256);
		vector<int> visited(256);
		for (int i = 0; i < s.size(); ++i)
		{
			if (mapping[s[i]])
			{
				if (mapping[s[i]] != t[i])
					return false;
			}
			else
			{
				if (visited[t[i]])
					return false;
				visited[t[i]] = 1;
				mapping[s[i]] = t[i];
			}
		}
		return true;
	}
};