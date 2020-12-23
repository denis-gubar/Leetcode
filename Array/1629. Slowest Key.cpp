class Solution {
public:
	char slowestKey(vector<int>& releaseTimes, string keysPressed) {
		vector<int> M(128);
		int prev = 0;
		for (int i = 0; i < releaseTimes.size(); ++i)
		{
			int cur = releaseTimes[i];
            char c = keysPressed[i];
			M[c] = max(M[c], cur - prev);
			prev = cur;
		}
		int best = *max_element(M.begin(), M.end());
		char result = 'a';
		for (char c = 'a'; c <= 'z'; ++c)
			if (M[c] == best)
				result = c;
		return result;
	}
};