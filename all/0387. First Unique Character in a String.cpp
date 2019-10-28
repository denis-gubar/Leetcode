class Solution {
public:
	int firstUniqChar(string s) {
		vector<int> visited(26);
		for (char c : s)
			++visited[c - 'a'];
		for (int i = 0; i < s.size(); ++i)
			if (visited[s[i] - 'a'] == 1)
				return i;
		return -1;
	}
};