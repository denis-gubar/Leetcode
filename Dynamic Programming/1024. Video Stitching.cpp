class Solution {
public:
	int videoStitching(vector<vector<int>>& clips, int T) {
		sort(clips.begin(), clips.end());
		if (clips[0][0] > 0 || clips.back()[1] < T)
			return -1;
		int result = 1, left = clips[0][0], right = clips[0][1], current = clips[0][1];
		if (current >= T)
			return result;
		for (int i = 1; i < clips.size(); ++i)
		{
			if (clips[i][0] > current)
				return -1;
			if (clips[i][0] == left)
			{
				right = clips[i][1];
				current = max(current, right);
				if (current >= T)
					return result;
			}
			if (clips[i][0] > right)
			{
				left = clips[i][0];
				right = current;
				++result;
			}
			if (clips[i][1] > current)
			{
				current = clips[i][1];
				if (current >= T)
					return result + 1;
			}
		}
		return -1;
	}
};