class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int result = 0, last = -1;
		vector<int> lastVisited(256, -1);
		for (int i = 0; i < s.size(); ++i)
		{
            last = max(last, lastVisited[s[i]] + 1);
			lastVisited[s[i]] = i;
            result = max(result, i - last + 1);
		}        
		return result;
	}
};